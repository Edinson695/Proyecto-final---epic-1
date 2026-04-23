//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_PF_EPIC1_FEATURE1_V2026_01_TENSOR_BACKEND_H
#define PROG3_PF_EPIC1_FEATURE1_V2026_01_TENSOR_BACKEND_H
#pragma once
#include <Eigen/Dense>
#include <cstddef>
#include <span>
#include <stdexcept>
#include <vector>
#include "utec/algebra/shape.h"

namespace utec::tf {
    template <typename T>
    class Tensor {
    public:
        Tensor() = default;
        explicit Tensor(const Shape& shape);
        Tensor(const Shape& shape, const std::vector<T>& values);
        static Tensor zeros(const Shape& shape);
        static Tensor ones(const Shape& shape);
        static Tensor from_data(const Shape& shape, const std::vector<T>& values);
        [[nodiscard]] const Shape& shape() const noexcept;
        [[nodiscard]] std::size_t rank() const noexcept;
        [[nodiscard]] std::size_t numel() const noexcept;
        template <typename... Ix>
        T& operator()(Ix... indices);
        template <typename... Ix>
        const T& operator()(Ix... indices) const;
        Tensor reshape(const Shape& new_shape) const;
        Tensor operator+(const Tensor& other) const;
    private:
        Shape shape_;
        Eigen::Array<T, Eigen::Dynamic, 1> data_;
        [[nodiscard]] std::size_t flat_index(std::span<const int> indices) const;
    };

    template <typename T>
    Tensor<T>::Tensor(const Shape& shape)
    : shape_(shape), data_(static_cast<Eigen::Index>(shape.numel())) {
        data_.setZero();
    }
    template <typename T>
    std::size_t Tensor<T>::flat_index(std::span<const int> indices) const {
        if (indices.size() != shape_.rank()) {
            throw std::invalid_argument("numero de indices incompatible con el rank");
        }
        std::size_t flat = 0;
        std::size_t stride = 1;
        for (std::size_t i = shape_.rank(); i-- > 0;) {
            const int dim = shape_[i];
            const int idx = indices[i];
            if (idx < 0 || idx >= dim) {
                throw std::out_of_range("indice fuera de rango");
            }
            flat += static_cast<std::size_t>(idx) * stride;
            stride *= static_cast<std::size_t>(dim);
        }
        return flat;
    }
    template <typename T>
    Tensor<T> Tensor<T>::zeros(const Shape& shape) {
        Tensor<T> out(shape);
        out.data_.setZero();
        return out;
    }

    template<typename T>
    Tensor<T> Tensor<T>::ones(const Shape &shape) {
        Tensor<T> out(shape);
        out.data_.setOnes();
        return out;
    }

    template <typename T>
    template <typename... Ix>
    T& Tensor<T>::operator()(Ix... indices) {
        const int idx[] = {static_cast<int>(indices)...};
        return data_(static_cast<Eigen::Index>(
            flat_index(std::span<const int>(idx, sizeof...(indices)))));
    }

    template <typename T>
    template <typename... Ix>
    const T& Tensor<T>::operator()(Ix... indices) const {
        const int idx[] = {static_cast<int>(indices)...};
        return data_(static_cast<Eigen::Index>(
            flat_index(std::span<const int>(idx, sizeof...(indices)))));
    }

}



#endif //PROG3_PF_EPIC1_FEATURE1_V2026_01_TENSOR_BACKEND_H

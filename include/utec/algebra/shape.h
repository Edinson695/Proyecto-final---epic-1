#ifndef PROG3_PF_EPIC1_FEATURE1_V2026_01_SHAPE_H
#define PROG3_PF_EPIC1_FEATURE1_V2026_01_SHAPE_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <vector>

namespace utec::tf {
    class Shape {
    public:
        Shape() = default;
        Shape(std::initializer_list<int> dims);
        explicit Shape(std::vector<int> dims);
        [[nodiscard]] std::size_t rank() const noexcept;
        [[nodiscard]] std::size_t numel() const;
        [[nodiscard]] const std::vector<int>& dims() const noexcept;
        [[nodiscard]] int operator[](std::size_t i) const;
        friend bool operator==(const Shape&, const Shape&) = default;

    private:
        std::vector<int> dims_;
        void validate() const;
    };
}


#endif //PROG3_PF_EPIC1_FEATURE1_V2026_01_SHAPE_H

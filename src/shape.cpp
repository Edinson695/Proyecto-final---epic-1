#include "utec/algebra/shape.h"

namespace utec::tf {
    void Shape::validate() const {
        for (int dim : dims_) {
            if (dim <= 0) {
                throw std::invalid_argument("toda dimension debe ser positiva");
            }
        }
    }

    Shape::Shape(std::initializer_list<int> dims) : dims_(dims) {
        validate();
    }

    Shape::Shape(std::vector<int> dims) : dims_(dims) {
        validate();
    }

    size_t Shape::rank() const noexcept {
        return dims_.size();
    }

    size_t Shape::numel() const {
        std::size_t total = 1;
        for (const int& d : dims_ ) {
            total *= d;
        }
        return total;
    }

    const std::vector<int>& Shape::dims() const noexcept {
        return dims_;
    }

    int Shape::operator[](std::size_t i) const {
        return dims_[i];
    }
}
# Task #PF-EPIC1-Feature1: Proyecto Final - Epic 1 - Feature 1 - Integración de Eigen y backend base  
**course:** Programación III  
**unit:** final project  
**cmake project:** prog3_pf_epic1_feature1_v2026_01
## Indicaciones Específicas
El tiempo límite para la evaluación es 2 semanas.

Cada pregunta deberá ser respondida manteniendo la estructura del proyecto:

 - `include/utec/algebra/shape.h`
 - `include/utec/algebra/tensor_backend.h`
 - `src/*.cpp`
 
Para la entrega, genera el archivo `.zip` con el script en `scripts/`:

```bash
bash scripts/generate_zip.sh
```

En Windows también puedes usar:

```powershell
powershell -ExecutionPolicy Bypass -File scripts/generate_zip.ps1
```

o:

```bat
scripts\generate_zip.bat
```

Este comando crea `prog3_pf_epic1_feature1_v2026_01.zip` en la raíz del proyecto. Ese es el archivo que debes subir a www.gradescope.com.

## Question #1 - Shape - dimensiones y metadatos (4 points)
  
Implementa la clase `Shape` para representar dimensiones dinámicas válidas. Los tests verifican construcción desde lista de inicialización y desde `std::vector<int>`, cálculo correcto de `rank()` y `numel()`, acceso por índice mediante `operator[]`, comparación entre shapes y validación de dimensiones inválidas. Debe lanzarse `std::invalid_argument` cuando alguna dimensión sea menor o igual a cero.  
  
**Use Case:**  
```cpp
using utec::tf::Shape;

Shape shape{2, 3, 4};
std::cout << shape.rank() << '\n';   // 3
std::cout << shape.numel() << '\n';  // 24

Shape same_shape(std::vector<int>{2, 3, 4});
std::cout << std::boolalpha << (shape == same_shape) << '\n';

```

## Question #2 - Tensor - zeros (2 points)
  
Implementa la fábrica `Tensor<T>::zeros(const Shape&)`. Los tests verifican que el tensor se construya con la forma pedida, que todos sus elementos se inicialicen en cero y que la creación falle si el `Shape` es inválido.  
  
**Use Case:**  
```cpp
using utec::tf::Shape;
using utec::tf::Tensor;

auto tensor = Tensor<int>::zeros(Shape{2, 3});
std::cout << tensor(0, 0) << ' ' << tensor(1, 2) << '\n';  // 0 0

```

## Question #3 - Tensor - ones (1 points)
  
Implementa la fábrica `Tensor<T>::ones(const Shape&)`. Los tests verifican que todos los elementos queden inicializados en uno y que el tensor pueda manipularse luego con acceso por índices sin corromper los demás valores.  
  
**Use Case:**  
```cpp
using utec::tf::Shape;
using utec::tf::Tensor;

auto tensor = Tensor<int>::ones(Shape{2, 2});
std::cout << tensor(0, 0) << ' ' << tensor(1, 1) << '\n';  // 1 1

```

## Question #4 - Tensor - rank, numel, shape (1 points)
  
Implementa los metadatos básicos del tensor: `rank()`, `numel()` y `shape()`. Los tests verifican que el tensor exponga correctamente su rango, la cantidad total de elementos y la forma exacta con la que fue construido.  
  
**Use Case:**  
```cpp
using utec::tf::Shape;
using utec::tf::Tensor;

auto tensor = Tensor<float>::ones(Shape{2, 3, 4});
std::cout << tensor.rank() << '\n';   // 3
std::cout << tensor.numel() << '\n';  // 24
std::cout << std::boolalpha << (tensor.shape() == Shape{2, 3, 4}) << '\n';

```

## Question #5 - Tensor - from_data y acceso por índices (4 points)
  
Implementa la construcción desde datos externos con `from_data` y el acceso multidimensional mediante `operator()`. Los tests verifican lectura y escritura por índice, preservación del orden lineal de los datos, validación de cantidad incorrecta de datos y detección de accesos fuera de rango con `std::out_of_range`.  
  
**Use Case:**  
```cpp
using utec::tf::Shape;
using utec::tf::Tensor;

auto tensor = Tensor<int>::from_data(Shape{2, 3}, {1, 2, 3, 4, 5, 6});
tensor(0, 1) = 20;

std::cout << tensor(0, 0) << ' ' << tensor(0, 1) << ' ' << tensor(1, 2) << '\n';
// 1 20 6

```

## Question #6 - Tensor - reshape (4 points)
  
Implementa `reshape` para reinterpretar la forma del tensor sin alterar sus datos. Los tests verifican un reshape compatible, conservación del orden de los elementos y lanzamiento de `std::invalid_argument` cuando el nuevo `Shape` no preserva `numel()`.  
  
**Use Case:**  
```cpp
using utec::tf::Shape;
using utec::tf::Tensor;

auto tensor = Tensor<int>::from_data(Shape{2, 3}, {1, 2, 3, 4, 5, 6});
auto reshaped = tensor.reshape(Shape{3, 2});

std::cout << reshaped(0, 0) << ' ' << reshaped(2, 1) << '\n';
// 1 6

```

## Question #7 - Tensor - suma elemento a elemento (4 points)
  
Implementa `operator+` para sumar dos tensores de igual forma, devolviendo un nuevo tensor. Los tests verifican el resultado de la suma elemento a elemento, que los operandos originales no sean modificados y que se lance `std::invalid_argument` cuando las formas sean incompatibles.  
  
**Use Case:**  
```cpp
using utec::tf::Shape;
using utec::tf::Tensor;

auto a = Tensor<int>::from_data(Shape{2, 2}, {0, 1, 2, 3});
auto b = Tensor<int>::ones(Shape{2, 2});
auto c = a + b;

std::cout << c(0, 0) << ' ' << c(1, 1) << '\n';  // 1 4

```

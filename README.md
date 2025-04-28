# 🌀 Class `mix`

Unlike standard C++ containers like std::vector, which require specifying the type of the stored elements at the time of declaration, the mix class provides a groundbreaking approach. It allows storing objects of unknown or heterogeneous types within a single container, determined dynamically during runtime. This flexibility eliminates the constraints of type homogeneity and opens up new possibilities for dynamic applications, making it highly adaptable for scenarios where types cannot be predetermined.

With mix, developers can insert elements of any type into the same container without wrapping them into a polymorphic base or using complex type-erasing mechanisms like std::variant or std::any. The class leverages pointers and dynamic type casting to achieve this, while maintaining ease of use and high performance. 🌟

## 🧪 Class Overview
The class uses a vector of pointers (`std::vector<void*>`) as its base structure, allowing for the storage of heterogeneous data without type constraints.

## 🚀 Key Features
- **Operators**:
  - `[]`: Accesses the pointer to an element (equivalent to `&container.get<void>()`)
  - `+=`: Adds elements from another mix container to the current one
  - `==`: Compares two `mix` objects
  - `!=`: Checks inequality between two `mix` objects
  - `+`:  Returns a new `mix` object combining two instances

- **Element Access**:
  - `at(int index)`: Retrieves the element at the given index, cast to the specified type

- **Insertion and Removal**:
  - `erase(int index)`: Erases the element at the given position
  - `find(T const element)`: Finds the index of a specific element (functionality pending)
  - `insert(T element, int index = -1)`: Inserts an element of a generic type at the specified position
  - `pop_back()`: Removes the last element in the container
  - `push_back(T element)`: Appends an element to the container
  - `remove(T const element)`: Removes a specific element (functionality to be completed)

- **Container Management**:
  - `size()`: Returns the total number of elements
  - `capacity()`: Provides the internal vector's capacity
  - `clear()`: Removes all elements from the container
  - Iterators: `begin()` and `end()` for seamless iteration

## 💡 How to Use `mix`

### Install using CMake
```cmake
cmake_minimum_required(VERSION 3.14)

PROJECT(myproject)

# fetch latest mix
include(FetchContent)
FetchContent_Declare(
    mix
    GIT_REPOSITORY https://github.com/giovanni-iannaccone/mix.git
)
FetchContent_MakeAvailable(mix)

add_executable(myproject main.cpp)
target_link_libraries(myproject mix)
```

### Include `mix` in your project
```cpp
#include <mix/mix.hpp>
```

### Usage Example
```cpp
#include <iostream>
#include <string>

#include <mix/mix.hpp>

int main() {
    mix container;

    // Insert elements of different types
    container.insert<int>(42); // Integer
    container.insert<std::string>("Hello World"); // String

    // Retrieve elements
    int intValue = container.at<int>(0);
    std::string strValue = container.at<std::string>(1);

    std::cout << "Integer: " << intValue << "\\n";
    std::cout << "String: " << strValue << "\\n";

    return 0;
}
```

# 🧩 Contributing
We welcome contributions! Please follow these steps:

1. Fork the repository.
2. Create a new branch ( using <a href="https://medium.com/@abhay.pixolo/naming-conventions-for-git-branches-a-cheatsheet-8549feca2534">this</a> convention).
3. Make your changes and commit them with descriptive messages.
4. Push your changes to your fork.
5. Create a pull request to the main repository.

### 🍃 Contributors
<a href="https://github.com/giovanni-iannaccone/mix/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=giovanni-iannaccone/mix"  alt="mix Contributors"/>
</a>

## ⚖ License
This project is licensed under the GPL-3.0 License. See the LICENSE file for details.

## ⚔ Contact
- For any inquiries or support, please contact <a href="mailto:iannacconegiovanni444@gmail.com"> iannacconegiovanni444@gmail.com </a>.
- Visit my site for more informations about me and my work <a href="https://giovanni-iannaccone.gith
ub.io" target=”_blank” rel="noopener noreferrer"> https://giovanni-iannaccone.github.io </a>

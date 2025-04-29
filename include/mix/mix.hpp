#pragma once

#include <vector>

class mix {

protected:
    std::vector<void *> ptrs;

public:

    ~mix() {
        this->ptrs.clear();
    }

    auto operator[](size_t const index) -> void* {
        return this->ptrs[index];
    }

    auto operator==(mix const &obj) -> bool {
        if (this->ptrs.size() != obj.ptrs.size())
            return false;

        for (size_t i = 0; i < this->ptrs.size(); i++)
            if (this->ptrs[i] != obj.ptrs[i])
                return false;
        
        return true;
    }

    auto operator!=(mix const &obj) -> bool {
        if (this->ptrs.size() != obj.ptrs.size())
            return true;

        for (size_t i = 0; i < this->ptrs.size(); i++)
            if (this->ptrs[i] != obj.ptrs[i])
                return true;
        
        return false;
    }

    auto operator+=(mix const &obj) -> mix {
        for (void *ptr: obj.ptrs)
            this->ptrs.push_back(ptr);
        
        return *this;
    }

    template <typename T>
    auto at(size_t const index) -> T {
        return *static_cast<T *>(this->ptrs.at(index));
    }

    auto back() -> void* {
        return this->ptrs.back();
    }

    auto begin() -> std::vector<void *>::iterator {
        return this->ptrs.begin();
    }

    auto capacity() -> size_t {
        return this->ptrs.capacity();
    }

    auto clear() -> void {
        this->ptrs.clear();
    }

    auto end() -> std::vector<void *>::iterator {
        return this->ptrs.end();
    }

    auto erase(int index = -1) -> void {
        if (index < 0 || index > this->ptrs.size())
            index = this->ptrs.size() - 1;

        this->ptrs.erase(this->ptrs.begin() + index);
    }

    template <typename T>
    auto find(T element) -> size_t {
        for (size_t i = 0; i < this->ptrs.size(); i++)
            if (this->at<T>(i) == element)
                return i;
        
        return -1;
    }

    template <typename T>
    auto insert(T const element, int index = -1) -> void {

        if (index < 0 || index > this->ptrs.size())
            index = this->ptrs.size();

        this->ptrs.insert(this->ptrs.begin() + index, (void *)(new T(element)));
    }

    auto pop_back() -> void {
        this->ptrs.pop_back();
    }

    template <typename T>
    auto push_back(T const element) -> void {
        this->insert<T>(element, this->ptrs.size());
    }

    template <typename T>
    auto remove(T const element) -> void {
        for (size_t i = 0; i < this->ptrs.size(); i++)
            if (this->at<T>(i) == element)
                this->ptrs.erase(this->ptrs.begin() + i);
    }

    auto size() -> size_t {
        return this->ptrs.size();
    }


};
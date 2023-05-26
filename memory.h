#pragma once

#include <iostream>
#include <stdexcept>

namespace custom {
	template<class T>
	class unique_ptr {
	public:
		unique_ptr(T* ptr) : raw_ptr(ptr) {}
		unique_ptr(const unique_ptr&) = delete;
		~unique_ptr() {
			if(raw_ptr != nullptr) delete raw_ptr;
		}
		unique_ptr& operator=(const unique_ptr&) = delete;
		T operator*() {
			return (*raw_ptr);
		}
		T* release() {
			T* tmp_ptr = raw_ptr;
			raw_ptr = nullptr;
			return tmp_ptr;
		}
	private:
		T* raw_ptr;
	};

	template<class T>
	class unique_ptr<T[]> {
	public:
		unique_ptr(T* ptr) : raw_ptr(ptr) {}
		unique_ptr(const unique_ptr&) = delete;
		~unique_ptr() {
			delete[] raw_ptr;
		}
		unique_ptr& operator=(const unique_ptr&) = delete;
		T operator*() {
			return (*raw_ptr);
		}
		T* release() {
			T* tmp_ptr = raw_ptr;
			raw_ptr = nullptr;
			return tmp_ptr;
		}
		T& operator[](const int idx) {
			if(idx < 0) throw std::out_of_range("negative index");
			
			return raw_ptr[idx];
		}
	private:
		T* raw_ptr;
	};
}


/**
 * @file dynamicArray.hpp
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief A template for implementing a nifty dynamic array.
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once
#include <cstddef>
#include <initializer_list>
#include <algorithm>

namespace csci325
{
    /**
     * @brief A dynamic array that also allows for resizing.
     *
     * @tparam T
     */
    template <typename T>
    class DynamicArray
    {
    public:
        /**
         * @brief Construct an empty dynamic array.
         *
         */
        DynamicArray();

        /**
         * @brief Construct a dynamic array with size elements.
         *
         * @param size
         */
        DynamicArray(std::size_t size);

        /**
         * @brief Construct a dynamic array with size copies of value.
         *
         * @param size
         * @param value
         */
        DynamicArray(std::size_t size, const T &value);

        /**
         * @brief Construct a new Dynamic Array object from an initializer list.
         *
         * @param init
         */
        DynamicArray(std::initializer_list<T> init);

        /**
         * @brief Copy constructor
         *
         * @param other
         */
        DynamicArray(const DynamicArray<T> &other);

        /**
         * @brief Destroy the Dynamic Array object
         *
         */
        virtual ~DynamicArray();

        /**
         * @brief Return the size of the dynamic array.
         *
         * @return std::size_t
         */
        virtual std::size_t size() const;

        /**
         * @brief Resize the dynamic array, growing or shrinking as needed.
         *
         */
        virtual void resize(std::size_t size);

        /**
         * @brief Index operator
         *
         * @param index
         * @return T&
         */
        virtual T &operator[](int index);

        /**
         * @brief Assignment operator
         *
         * @param other
         * @return DynamicArray<T>&
         */
        virtual DynamicArray<T> &operator=(const DynamicArray<T> &other);

        // ----- Random-access iterator (non-const) -----
        class iterator
        {
        public:
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using reference = T &;
            using pointer = T *;
            using iterator_category = std::random_access_iterator_tag;

            iterator() = default;
            explicit iterator(pointer p) : p_(p) {}

            // Dereference
            reference operator*() const { return *p_; }
            pointer operator->() const { return p_; }

            // ++ / --
            iterator &operator++()
            {
                ++p_;
                return *this;
            }
            iterator operator++(int)
            {
                iterator t(*this);
                ++*this;
                return t;
            }
            iterator &operator--()
            {
                --p_;
                return *this;
            }
            iterator operator--(int)
            {
                iterator t(*this);
                --*this;
                return t;
            }

            // += / -=
            iterator &operator+=(difference_type n)
            {
                p_ += n;
                return *this;
            }
            iterator &operator-=(difference_type n)
            {
                p_ -= n;
                return *this;
            }

            // + / -
            friend iterator operator+(iterator it, difference_type n)
            {
                it += n;
                return it;
            }
            friend iterator operator+(difference_type n, iterator it)
            {
                it += n;
                return it;
            }
            friend iterator operator-(iterator it, difference_type n)
            {
                it -= n;
                return it;
            }

            // Distance
            friend difference_type operator-(const iterator &a, const iterator &b) { return a.p_ - b.p_; }

            // Indexing
            reference operator[](difference_type n) const { return *(*this + n); }

            // Comparisons
            friend bool operator==(const iterator &a, const iterator &b) { return a.p_ == b.p_; }
            friend bool operator!=(const iterator &a, const iterator &b) { return !(a == b); }
            friend bool operator<(const iterator &a, const iterator &b) { return a.p_ < b.p_; }
            friend bool operator>(const iterator &a, const iterator &b) { return b < a; }
            friend bool operator<=(const iterator &a, const iterator &b) { return !(b < a); }
            friend bool operator>=(const iterator &a, const iterator &b) { return !(a < b); }

            // Expose raw pointer for interop (optional)
            pointer base() const { return p_; }

        private:
            pointer p_ = nullptr;
        };

        // ----- Random-access const_iterator -----
        class const_iterator
        {
        public:
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using reference = const T &;
            using pointer = const T *;
            using iterator_category = std::random_access_iterator_tag;

            const_iterator() = default;
            explicit const_iterator(pointer p) : p_(p) {}
            // Allow implicit conversion from iterator
            const_iterator(iterator it) : p_(it.base()) {}

            reference operator*() const { return *p_; }
            pointer operator->() const { return p_; }

            const_iterator &operator++()
            {
                ++p_;
                return *this;
            }
            const_iterator operator++(int)
            {
                const_iterator t(*this);
                ++*this;
                return t;
            }
            const_iterator &operator--()
            {
                --p_;
                return *this;
            }
            const_iterator operator--(int)
            {
                const_iterator t(*this);
                --*this;
                return t;
            }

            const_iterator &operator+=(difference_type n)
            {
                p_ += n;
                return *this;
            }
            const_iterator &operator-=(difference_type n)
            {
                p_ -= n;
                return *this;
            }

            friend const_iterator operator+(const_iterator it, difference_type n)
            {
                it += n;
                return it;
            }
            friend const_iterator operator+(difference_type n, const_iterator it)
            {
                it += n;
                return it;
            }
            friend const_iterator operator-(const_iterator it, difference_type n)
            {
                it -= n;
                return it;
            }

            friend difference_type operator-(const const_iterator &a, const const_iterator &b) { return a.p_ - b.p_; }

            reference operator[](difference_type n) const { return *(*this + n); }

            friend bool operator==(const const_iterator &a, const const_iterator &b) { return a.p_ == b.p_; }
            friend bool operator!=(const const_iterator &a, const const_iterator &b) { return !(a == b); }
            friend bool operator<(const const_iterator &a, const const_iterator &b) { return a.p_ < b.p_; }
            friend bool operator>(const const_iterator &a, const const_iterator &b) { return b < a; }
            friend bool operator<=(const const_iterator &a, const const_iterator &b) { return !(b < a); }
            friend bool operator>=(const const_iterator &a, const const_iterator &b) { return !(a < b); }

            pointer base() const { return p_; }

            // Cross-type comparisons (iterator vs const_iterator)
            friend bool operator==(const_iterator a, iterator b) { return a.p_ == b.base(); }
            friend bool operator==(iterator a, const_iterator b) { return b == a; }
            friend bool operator!=(const_iterator a, iterator b) { return !(a == b); }
            friend bool operator!=(iterator a, const_iterator b) { return !(a == b); }

        private:
            pointer p_ = nullptr;
        };

        //////////////////////////////////////////
        // Iterator Access Functions
        //////////////////////////////////////////
        iterator begin() noexcept { return iterator(data); }
        iterator end() noexcept { return iterator(data + data_size); }
        const_iterator begin() const noexcept { return const_iterator(data); }
        const_iterator end() const noexcept { return const_iterator(data + data_size); }
        const_iterator cbegin() const noexcept { return begin(); }
        const_iterator cend() const noexcept { return end(); }


        //////////////////////////////////////////
        // Back and front accessors
        //////////////////////////////////////////
        T& front() { return data[0]; }
        T& back() { return data[data_size-1]; }

    private:
        T *data;
        std::size_t data_size;
    };

    // Construct an empty dynamic array.
    template <typename T>
    DynamicArray<T>::DynamicArray()
    {
        // nothing to store
        data = nullptr;
        data_size = 0;
    }

    // Construct a dynamic array with size elements.
    template <typename T>
    DynamicArray<T>::DynamicArray(std::size_t size) : DynamicArray<T>(size, T())
    {
        // handled via constructor delegation
    }

    // Construct a dynamic array with size copies of value.
    template <typename T>
    DynamicArray<T>::DynamicArray(std::size_t size, const T &value)
    {
        // allocate the array
        data = new T[size];
        data_size = size;

        for (int i = 0; i < size; i++)
        {
            data[i] = value;
        }
    }

    // Construct a new Dynamic Array object from an initializer list.
    template <typename T>
    DynamicArray<T>::DynamicArray(std::initializer_list<T> init)
    {
        // allocate the array
        data_size = init.size();
        data = new T[data_size];

        // copy the list
        auto it = init.begin();
        for (int i = 0; i < data_size; i++)
        {
            data[i] = *it;
            it++;
        }
    }

    // Copy constructor
    template <typename T>
    DynamicArray<T>::DynamicArray(const DynamicArray<T> &other)
    {
        // leverage the assignment operator
        data = nullptr;
        data_size = 0;
        *this = other;
    }

    // Destroy the Dynamic Array object
    template <typename T>
    DynamicArray<T>::~DynamicArray()
    {
        delete[] data;
    }

    // Return the size of the dynamic array.
    template <typename T>
    std::size_t DynamicArray<T>::size() const
    {
        return data_size;
    }

    // Resize the dynamic array, growing or shrinking as needed.
    template <typename T>
    void DynamicArray<T>::resize(std::size_t size)
    {
        T *ndata;
        std::size_t copy_size = std::min(size, data_size);

        // allocate the new data array
        if (size > 0)
        {
            ndata = new T[size];
        }
        else
        {
            ndata = nullptr;
        }

        // copy the data
        for (int i = 0; i < copy_size; i++)
        {
            ndata[i] = data[i];
        }

        // delete the old array
        delete[] data;

        // incorporate the new array
        data = ndata;
        data_size = size;
    }

    // Index operator
    template <typename T>
    T &DynamicArray<T>::operator[](int index)
    {
        return data[index];
    }

    // Assignment operator
    template <typename T>
    DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other)
    {
        if (data)
        {
            delete[] data;
        }

        // allocate the array
        data_size = other.data_size;
        data = new T[data_size];

        // copy the list
        for (int i = 0; i < data_size; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }
} // namespace csci325
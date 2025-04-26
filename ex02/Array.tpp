#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : _size(0), _data(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(n ? new T[n]() : 0) {}

template<typename T>
Array<T>::Array(const Array& other) 
    : _size(other._size), 
    _data(other._size ? new T[other._size]() : 0) 
{
    for (std::size_t i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template<typename T>
Array<T>::~Array() {
    delete[] _data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _data = _size ? new T[_size]() : 0;
        for (size_t i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int idx) {
    if (idx >= _size)
        throw Array<T>::OutofBoundError();
    return _data[idx];
}

template<typename T>
T const& Array<T>::operator[](unsigned int idx) const {
    if (idx >= _size)
        throw Array<T>::OutofBoundError();
    return _data[idx];
}

template<typename T>
unsigned int Array<T>::size() const { return _size; }

template<typename T>
const char* Array<T>::OutofBoundError::what() const throw() {
    return "Out of Bound Error!";
}

#endif
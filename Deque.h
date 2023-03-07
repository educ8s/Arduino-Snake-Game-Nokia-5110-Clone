template <typename T>
class Deque {
public:
    Deque() : _size(0), _front(0), _back(0), _capacity(4), _data(new T[4]) {}


void push_back(const T& value) {
    if (_size == _capacity) {
        _resize(_capacity * 2);
    }
    _data[_back] = value;
    _back = (_back + 1) % _capacity;
    ++_size;
}

void push_front(const T& value) {
    if (_size == _capacity) {
        _resize(_capacity * 2);
    }
    _front = (_front - 1 + _capacity) % _capacity;
    _data[_front] = value;
    ++_size;
}

    void pop_back() {
        if (_size == 0) {
            // handle underflow error
        } else {
            _back = (_back - 1 + _capacity) % _capacity;
            --_size;
            if (_size < _capacity / 4) {
                _resize(_capacity / 2);
            }
        }
    }

    void pop_front() {
        if (_size == 0) {
            // handle underflow error
        } else {
            _front = (_front + 1) % _capacity;
            --_size;
            if (_size < _capacity / 4) {
                _resize(_capacity / 2);
            }
        }
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    void clear() {
    _size = 0;
    _front = 0;
    _back = 0;
}

T& operator[](size_t index) {
    if (index < _size) {
        return _data[(_front + index) % _capacity];
    } else {
        // handle out of bounds error
        // you can throw an exception or return a default value
        // for example, return the last element
        return _data[(_front + _size - 1) % _capacity];
    }
}

private:
    size_t _size;
    size_t _front;
    size_t _back;
    size_t _capacity;
    T* _data;

void _resize(size_t newCapacity) {
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < _size; ++i) {
        newData[i] = _data[(_front + i) % _capacity];
    }
    _capacity = newCapacity;
    _front = 0;
    _back = _size;
    delete[] _data;
    _data = newData;
}
};
# Mydeque

> `deque` 的真实物理结构是中控+缓冲。这种结构在之后实现 `std::unorder_map` 里面写
>
> **这里的示例使用环形缓冲区实现。** 同样是C++11版本，支持迭代器操作



## 完整代码

```cpp
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

template <typename T>
class MyDeque
{
public:
  MyDeque(size_t initialCapacity = 8) // 构造函数，默认初始容量为8
      : capacity(initialCapacity), currentSize(0), frontIndex(0), backIndex(0)
  {
    data = new T[capacity](); // 分配内存,使用T的默认构造函数
  }
  ~MyDeque()
  {
    delete[] data; // 释放内存
  }

  bool empty() const
  {
    return currentSize == 0; // 判断是否为空
  }

  size_t size() const
  {
    return currentSize; // 获取当前元素数量
  }

  void resize(size_t newCapacity)
  {
    if (newCapacity <= capacity) // 如果新容量不大于当前容量，则不需要调整
      return;

    T *newData = new T[newCapacity]; // 分配新的内存,加()是显示调用但是会初始化，不加()则不初始化
    for (size_t i = 0; i < currentSize; ++i)
    {
      newData[i] = data[(frontIndex + i) % capacity]; // 复制元素到新数组
    }
    delete[] data;                             // 释放旧内存
    data = newData;                            // 更新指针
    capacity = newCapacity;                    // 更新容量
    frontIndex = 0;                            // 重置前端索引
    backIndex = static_cast<int>(currentSize); // 更新后端索引
  }

  void push_front(const T &value)
  {
    if (currentSize == capacity) // 如果当前容量已满，进行扩容
      resize(capacity * 2);

    frontIndex = (frontIndex - 1 + capacity) % capacity; // 更新前端索引
    data[frontIndex] = value;                            // 插入新元素
    ++currentSize;                                       // 增加元素数量
  }

  // 一般规定：前向指针指向第一个有效元素，后向指针指向最后一个有效元素的下一个位置
  // 因此，插入新元素时，前向指针需要向前移动再插入，后向指针就直接插入再移动
  void push_back(const T &value)
  {
    if (currentSize == capacity) // 如果当前容量已满，进行扩容
      resize(capacity * 2);

    data[backIndex] = value;                // 插入新元素
    backIndex = (backIndex + 1) % capacity; // 更新后端索引
    ++currentSize;                          // 增加元素数量
  }

  void pop_front()
  {
    if (empty()) // 如果队列为空，无法弹出
      throw std::out_of_range("Deque is empty");

    frontIndex = (frontIndex + 1) % capacity; // 更新前端索引
    --currentSize;                            // 减少元素数量
  }

  void pop_back()
  {
    if (empty()) // 如果队列为空，无法弹出
      throw std::out_of_range("Deque is empty");

    backIndex = (backIndex - 1 + capacity) % capacity; // 更新后端索引
    --currentSize;                                     // 减少元素数量
  }

  T &front()
  {
    if (empty()) // 如果队列为空，无法访问
      throw std::out_of_range("Deque is empty");

    return data[frontIndex]; // 返回前端元素
  }

  T &back()
  {
    if (empty()) // 如果队列为空，无法访问
      throw std::out_of_range("Deque is empty");

    return data[(backIndex - 1 + capacity) % capacity]; // 返回后端元素
  }

  T &operator[](size_t physicalIndex)
  {
    return data[physicalIndex];
  }

  const T &operator[](size_t physicalIndex) const
  {
    return data[physicalIndex];
  }

  class iterator
  {
  private:
    MyDeque *deque; // 指向所属的MyDeque对象
    size_t index;   // 当前迭代器位置

  public:
    using iterator_category = std::bidirectional_iterator_tag; // 双向迭代器
    using value_type = T;                                      // 迭代器的值类型
    using difference_type = std::ptrdiff_t;                    // 迭代器的差值类型
    using pointer = T *;                                       // 迭代器的指针类型
    using reference = T &;                                     // 迭代器的引用类型
    iterator(MyDeque *d, size_t i) : deque(d), index(i) {}     // 构造函数

    reference operator*() const
    {
      return (*deque)[index]; // 解引用操作
    }

    pointer operator->() const
    {
      return &(*deque)[index]; // 成员访问操作
    }

    iterator &operator++()
    {
      index = (index + 1) % deque->capacity; // 前向移动
      return *this;
    }

    iterator operator++(int)
    {
      iterator temp = *this; // 保存当前状态
      ++(*this);             // 前向移动
      return temp;           // 返回原状态
    }

    iterator &operator--()
    {
      index = (index - 1 + deque->capacity) % deque->capacity; // 后向移动
      return *this;
    }

    iterator operator--(int)
    {
      iterator temp = *this; // 保存当前状态
      --(*this);             // 后向移动
      return temp;           // 返回原状态
    }

    bool operator==(const iterator &other) const
    {
      return deque == other.deque && index == other.index; // 判断迭代器是否相等
    }

    bool operator!=(const iterator &other) const
    {
      return !(*this == other); // 判断迭代器是否不相等
    }
  };

  iterator begin()
  {
    return iterator(this, frontIndex); // 返回指向前端的迭代器
  }

  iterator end()
  {
    return iterator(this, backIndex); // 返回指向后端(尾后)的迭代器
  }

private:
  T *data;            // 内部数组
  size_t capacity;    // 数组容量
  size_t currentSize; // 当前元素数量
  int frontIndex;     // 前端索引
  int backIndex;      // 后端索引
};

int main()
{
  MyDeque<std::string> dq;

  // 在后面插入元素
  dq.push_back("Apple");
  dq.push_back("Banana");
  dq.push_back("Cherry");

  // 在前面插入元素
  dq.push_front("Date");
  dq.push_front("Elderberry");

  // 显示队列大小
  std::cout << "Deque 大小: " << dq.size() << std::endl;

  // 使用迭代器进行遍历
  std::cout << "Deque 元素: ";
  for (auto it = dq.begin(); it != dq.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // 访问前端和后端元素
  std::cout << "前端元素: " << dq.front() << std::endl;
  std::cout << "后端元素: " << dq.back() << std::endl;

  // 删除元素
  dq.pop_front();
  dq.pop_back();

  // 再次遍历
  std::cout << "删除元素后的 Deque: ";
  for (auto it = dq.begin(); it != dq.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  return 0;
}
```




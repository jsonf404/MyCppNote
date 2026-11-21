# Mylist

> 手写一个双向链表，C++11版本，**有迭代器功能实现** 



## 节点类

```cpp
template <typename T>
struct Node
{
  T data;
  Node *prev;
  Node *next;

  Node(const T &value = T()) : data(value), prev(nullptr), next(nullptr) {}
};
```

---

包含：数据域、前向指针、后向指针。构造函数。

> 无参构造 `Node()` 要看T的类型，内置类型有默认构造如 `int()` 。自定义复合类型要保证其有无参构造。



## 迭代器类

### 类型别名

C++ 的标准库算法（如 `std::distance`）需要知道迭代器的特性。通过这些别名，算法可以在编译期通过 `std::iterator_traits` 获取信息。如：

- **`iterator_category`**: 告诉编译器这是一个**双向迭代器**。这意味着它可以支持 `++` 和 `--`，但不支持像指针那样的随机跳转 `it + 5`。
- **`difference_type`**: 用来表示两个迭代器之间的距离（通常是 `long long` 或 `ptrdiff_t`）。



### 自增自减

- **前置 `++it` vs 后置 `it++`**：
  - **前置**：直接修改 `current` 指针并返回 `*this`（即自己）。不产生临时对象，**性能最高**。
  - **后置**：先用 `temp` 拷贝一份当前的自己，然后再自增，最后返回 `temp`。

---

```cpp
template <typename T>
class MyListIterator
{
public:
  using self_type = MyListIterator<T>;                       // 定义迭代器类型
  using value_type = T;                                      // 定义迭代器指向的元素类型
  using reference = T &;                                     // 定义迭代器指向的元素的引用类型
  using pointer = T *;                                       // 定义迭代器指向的元素的指针类型
  using iterator_category = std::bidirectional_iterator_tag; // 双向迭代器
  using difference_type = std::ptrdiff_t;                    // 定义迭代器之间的距离类型

  MyListIterator(Node<T> *ptr = nullptr) : current(ptr) {}

  // 返回迭代器指向的元素的引用 *it
  reference operator*()
  {
    return current->data;
  }

  // 返回迭代器指向的元素的指针 it->
  pointer operator->()
  {
    return &(current->data);
  }

  // 迭代器前置++it运算符，指向下一个元素。
  // 返回迭代器本身的引用，因为是++后返回自己，是左值，可以返回引用
  self_type &operator++()
  {
    if (current) // 防止指针本身为空，在后移就未定义了
      current = current->next;
    return *this;
  }

  // 后置it++运算符，指向下一个元素 int没有实际意义，只是表示这是后置递增运算符
  // 返回迭代器递增前的值，因为是it++后返回递增前的值，是右值，不能返回引用
  self_type operator++(int)
  {
    self_type temp = *this;
    ++(*this); // 自举，推荐这种写法
    return temp;
  }

  // 迭代器前置--it运算符，指向上一个元素
  self_type &operator--()
  {
    if (current) // 防止指针本身为空，在前移就未定义了
      current = current->prev;
    return *this;
  }

  // 后置it--运算符，指向上一个元素
  self_type operator--(int)
  {
    self_type temp = *this;
    --(*this); // 自举，推荐这种写法
    return temp;
  }

  // 判断两个迭代器是否相等
  bool operator==(const self_type &other) const
  {
    return current == other.current;
  }

  // 判断两个迭代器是否不相等
  bool operator!=(const self_type &other) const
  {
    return current != other.current;
  }

private:
  Node<T> *current;       // 迭代器当前指向的节点
  friend class MyList<T>; // 声明MyList为友元类，以便访问私有成员
};
```



## list类

### 迭代器使用

代码中很多如 `iterator(head->next)` 的写法，**本质是生成一个迭代器来操作链表元素**，即：

> 调用 `MyListIterator` 的构造函数，把 `head->next` 这个指针传进去，给我生成一个迭代器对象。”



### 哨兵

`head` 和 `tail` 是头尾哨兵节点

- 头结点前一个，尾节点后一个

- - 

### 成员函数

- - **构造函数**：初始化头尾哨兵，并将它们互相连接。

- - **析构函数**：清空链表并删除哨兵节点。

- - `insert`：在指定位置前插入新节点。

- - `erase`：删除指定位置的节点。

- - `push_front` **和** `push_back`：分别在头部和尾部插入元素。

- - `pop_front` **和** `pop_back`：分别删除头部和尾部元素。

- - `front` **和** `back`：访问头尾元素。

- - `empty` **和** `size`：检查链表是否为空和获取链表大小。

- - `clear`：清空链表。

- - `begin` **和** `end`：返回开始和结束迭代器。

- - `print`：辅助函数，用于打印链表内容。

```cpp
template <typename T>
class MyList
{
public:
  using iterator = MyListIterator<T>;       // 定义迭代器类型，数据成员就不用模板参数了
  using const_iterator = MyListIterator<T>; // 定义常量迭代器类型

  MyList()
  {
    head = new Node<T>(); // 创建头节点
    tail = new Node<T>(); // 创建尾节点
    head->next = tail;    // 头节点的下一个节点是尾节点
    tail->prev = head;    // 尾节点的上一个节点是头节点
  }

  ~MyList()
  {
    clear();     // 清空链表中有数据的元素
    delete head; // 删除头节点
    delete tail; // 删除尾节点
  }

  // 拷贝构造函数
  MyList(const MyList &other) : MyList() // 委托构造函数，调用默认构造函数初始化头尾节点
  {
    for (const auto &value : other) // 使用范围for循环遍历other链表中的元素
    {
      this->push_back(value); // 将other链表中的元素添加到当前链表的末尾
    }
  }

  // 拷贝赋值运算符
  MyList &operator=(const MyList &other)
  {
    if (this != &other) // 检查自赋值
    {
      clear();                        // 清空当前链表中的元素
      for (const auto &value : other) // 使用范围for循环遍历other链表中的元素
      {
        this->push_back(value); // 将other链表中的元素添加到当前链表的末尾
      }
    }
    return *this; // 返回当前对象的引用，以支持链式赋值
  }

  // 移动构造函数
  MyList(MyList &&other) noexcept : head(other.head), tail(other.tail) // 将other的头尾节点指针直接赋值给当前对象
  {
    other.head = nullptr; // 将other的头节点指针置空，防止析构时删除同一块内存
    other.tail = nullptr; // 将other的尾节点指针置空，防止析构时删除同一块内存
  }

  // 移动赋值运算符
  MyList &operator=(MyList &&other) noexcept
  {
    if (this != &other) // 检查自赋值
    {
      clear();              // 清空当前链表中的元素
      delete head;          // 删除当前链表的头节点
      delete tail;          // 删除当前链表的尾节点
      head = other.head;    // 将other的头节点指针直接赋值给当前对象
      tail = other.tail;    // 将other的尾节点指针直接赋值给当前对象
      other.head = nullptr; // 将other的头节点指针置空，防止析构时删除同一块内存
      other.tail = nullptr; // 将other的尾节点指针置空，防止析构时删除同一块内存
    }
    return *this; // 返回当前对象的引用，以支持链式赋值
  }

  iterator insert(const iterator &pos, const T &value)
  {
    Node<T> *newNode = new Node<T>(value); // 创建一个新的节点，存储要插入的值
    Node<T> *current = pos.current;        // 获取迭代器当前指向的节点

    // 将新节点插入到current之前
    newNode->prev = current->prev; // 新节点的前一个节点是current的前一个节点
    newNode->next = current;       // 新节点的下一个节点是current
    current->prev->next = newNode; // current的前一个节点的下一个节点是新节点
    current->prev = newNode;       // current的前一个节点是新节点

    return iterator(newNode); // 返回指向新节点的迭代器
  }

  iterator erase(const iterator &pos)
  {
    Node<T> *current = pos.current; // 获取迭代器当前指向的节点

    if (current == head || current == tail) // 如果当前节点是头节点或尾节点，不能删除
      return iterator(current);             // 返回当前节点的迭代器

    // 将current节点从链表中移除
    current->prev->next = current->next; // current的前一个节点的下一个节点是current的下一个节点
    current->next->prev = current->prev; // current的下一个节点的前一个节点是current的前一个节点

    iterator nextIt(current->next); // 创建一个指向current下一个节点的迭代器
    delete current;                 // 删除current节点

    return nextIt; // 返回指向current下一个节点的迭代器
  }

  void push_front(const T &value)
  {
    insert(iterator(head->next), value); // 在头节点的下一个节点之前插入新值
  }

  void push_back(const T &value)
  {
    insert(iterator(tail), value); // 在尾节点之前插入新值
  }

  void pop_front()
  {
    if (head->next != tail)        // 如果链表不为空
      erase(iterator(head->next)); // 删除头节点的下一个节点，即第一个元素
  }

  void pop_back()
  {
    if (tail->prev != head)        // 如果链表不为空
      erase(iterator(tail->prev)); // 删除尾节点的前一个节点，即最后一个元素
  }

  iterator begin()
  {
    return iterator(head->next); // 返回指向第一个元素的迭代器
  }

  iterator end()
  {
    return iterator(tail); // 返回指向尾节点的迭代器
  }

  T &front()
  {
    return head->next->data; // 返回第一个元素的引用
  }

  T &back()
  {
    return tail->prev->data; // 返回最后一个元素的引用
  }

  size_t size() const
  {
    size_t count = 0;
    Node<T> *cur = head->next; // 从第一个元素开始
    while (cur != tail)        // 遍历链表直到尾节点
    {
      ++count;         // 计数器加1
      cur = cur->next; // 移动到下一个节点
    }
    return count; // 返回链表中元素的数量
  }

  // 删除指定值的元素
  void remove(const T &value)
  {
    Node<T> *cur = head->next; // 从第一个元素开始
    while (cur != tail)        // 遍历链表直到尾节点
    {
      if (cur->data == value) // 如果当前节点的值等于要删除的值
      {
        cur->prev->next = cur->next; // 将当前节点的前一个节点的下一个节点指向当前节点的下一个节点
        cur->next->prev = cur->prev; // 将当前节点的下一个节点的前一个节点指向当前节点的前一个节点
        Node<T> *temp = cur;         // 保存当前节点的指针
        cur = cur->next;             // 移动到下一个节点
        delete temp;                 // 删除当前节点
      }
      else
      {
        cur = cur->next; // 如果当前节点的值不等于要删除的值，继续移动到下一个节点
      }
    }
  }

  void clear()
  {
    Node<T> *cur = head->next; // 从第一个元素开始
    while (cur != tail)        // 遍历链表直到尾节点
    {
      Node<T> *temp = cur; // 保存当前节点的指针
      cur = cur->next;     // 移动到下一个节点
      delete temp;         // 删除当前节点
    }
    head->next = tail; // 重新连接头节点和尾节点
    tail->prev = head;
  }

private:
  Node<T> *head; // 指向链表头节点的指针,哨兵节点
  Node<T> *tail; // 指向链表尾节点的指针，哨兵节点
};
```



## 完整代码

```cpp
#include <iostream>

template <typename T>
struct Node
{
  T data;
  Node *prev;
  Node *next;

  Node(const T &value = T()) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class MyList;

template <typename T>
class MyListIterator
{
public:
  using self_type = MyListIterator<T>;                       // 定义迭代器类型
  using value_type = T;                                      // 定义迭代器指向的元素类型
  using reference = T &;                                     // 定义迭代器指向的元素的引用类型
  using pointer = T *;                                       // 定义迭代器指向的元素的指针类型
  using iterator_category = std::bidirectional_iterator_tag; // 双向迭代器
  using difference_type = std::ptrdiff_t;                    // 定义迭代器之间的距离类型

  MyListIterator(Node<T> *ptr = nullptr) : current(ptr) {}

  // 返回迭代器指向的元素的引用 *it
  reference operator*()
  {
    return current->data;
  }

  // 返回迭代器指向的元素的指针 it->
  pointer operator->()
  {
    return &(current->data);
  }

  // 迭代器前置++it运算符，指向下一个元素。
  // 返回迭代器本身的引用，因为是++后返回自己，是左值，可以返回引用
  self_type &operator++()
  {
    if (current) // 防止指针本身为空，在后移就未定义了
      current = current->next;
    return *this;
  }

  // 后置it++运算符，指向下一个元素 int没有实际意义，只是表示这是后置递增运算符
  // 返回迭代器递增前的值，因为是it++后返回递增前的值，是右值，不能返回引用
  self_type operator++(int)
  {
    self_type temp = *this;
    ++(*this); // 自举，推荐这种写法
    return temp;
  }

  // 迭代器前置--it运算符，指向上一个元素
  self_type &operator--()
  {
    if (current) // 防止指针本身为空，在前移就未定义了
      current = current->prev;
    return *this;
  }

  // 后置it--运算符，指向上一个元素
  self_type operator--(int)
  {
    self_type temp = *this;
    --(*this); // 自举，推荐这种写法
    return temp;
  }

  // 判断两个迭代器是否相等
  bool operator==(const self_type &other) const
  {
    return current == other.current;
  }

  // 判断两个迭代器是否不相等
  bool operator!=(const self_type &other) const
  {
    return current != other.current;
  }

private:
  Node<T> *current;       // 迭代器当前指向的节点
  friend class MyList<T>; // 声明MyList为友元类，以便访问私有成员
};

template <typename T>
class MyList
{
public:
  using iterator = MyListIterator<T>;       // 定义迭代器类型，数据成员就不用模板参数了
  using const_iterator = MyListIterator<T>; // 定义常量迭代器类型

  MyList()
  {
    head = new Node<T>(); // 创建头节点
    tail = new Node<T>(); // 创建尾节点
    head->next = tail;    // 头节点的下一个节点是尾节点
    tail->prev = head;    // 尾节点的上一个节点是头节点
  }

  ~MyList()
  {
    clear();     // 清空链表中有数据的元素
    delete head; // 删除头节点
    delete tail; // 删除尾节点
  }

  // 拷贝构造函数
  MyList(const MyList &other) : MyList() // 委托构造函数，调用默认构造函数初始化头尾节点
  {
    for (const auto &value : other) // 使用范围for循环遍历other链表中的元素
    {
      this->push_back(value); // 将other链表中的元素添加到当前链表的末尾
    }
  }

  // 拷贝赋值运算符
  MyList &operator=(const MyList &other)
  {
    if (this != &other) // 检查自赋值
    {
      clear();                        // 清空当前链表中的元素
      for (const auto &value : other) // 使用范围for循环遍历other链表中的元素
      {
        this->push_back(value); // 将other链表中的元素添加到当前链表的末尾
      }
    }
    return *this; // 返回当前对象的引用，以支持链式赋值
  }

  // 移动构造函数
  MyList(MyList &&other) noexcept : head(other.head), tail(other.tail) // 将other的头尾节点指针直接赋值给当前对象
  {
    other.head = nullptr; // 将other的头节点指针置空，防止析构时删除同一块内存
    other.tail = nullptr; // 将other的尾节点指针置空，防止析构时删除同一块内存
  }

  // 移动赋值运算符
  MyList &operator=(MyList &&other) noexcept
  {
    if (this != &other) // 检查自赋值
    {
      clear();              // 清空当前链表中的元素
      delete head;          // 删除当前链表的头节点
      delete tail;          // 删除当前链表的尾节点
      head = other.head;    // 将other的头节点指针直接赋值给当前对象
      tail = other.tail;    // 将other的尾节点指针直接赋值给当前对象
      other.head = nullptr; // 将other的头节点指针置空，防止析构时删除同一块内存
      other.tail = nullptr; // 将other的尾节点指针置空，防止析构时删除同一块内存
    }
    return *this; // 返回当前对象的引用，以支持链式赋值
  }

  iterator insert(const iterator &pos, const T &value)
  {
    Node<T> *newNode = new Node<T>(value); // 创建一个新的节点，存储要插入的值
    Node<T> *current = pos.current;        // 获取迭代器当前指向的节点

    // 将新节点插入到current之前
    newNode->prev = current->prev; // 新节点的前一个节点是current的前一个节点
    newNode->next = current;       // 新节点的下一个节点是current
    current->prev->next = newNode; // current的前一个节点的下一个节点是新节点
    current->prev = newNode;       // current的前一个节点是新节点

    return iterator(newNode); // 返回指向新节点的迭代器
  }

  iterator erase(const iterator &pos)
  {
    Node<T> *current = pos.current; // 获取迭代器当前指向的节点

    if (current == head || current == tail) // 如果当前节点是头节点或尾节点，不能删除
      return iterator(current);             // 返回当前节点的迭代器

    // 将current节点从链表中移除
    current->prev->next = current->next; // current的前一个节点的下一个节点是current的下一个节点
    current->next->prev = current->prev; // current的下一个节点的前一个节点是current的前一个节点

    iterator nextIt(current->next); // 创建一个指向current下一个节点的迭代器
    delete current;                 // 删除current节点

    return nextIt; // 返回指向current下一个节点的迭代器
  }

  void push_front(const T &value)
  {
    insert(iterator(head->next), value); // 在头节点的下一个节点之前插入新值
  }

  void push_back(const T &value)
  {
    insert(iterator(tail), value); // 在尾节点之前插入新值
  }

  void pop_front()
  {
    if (head->next != tail)        // 如果链表不为空
      erase(iterator(head->next)); // 删除头节点的下一个节点，即第一个元素
  }

  void pop_back()
  {
    if (tail->prev != head)        // 如果链表不为空
      erase(iterator(tail->prev)); // 删除尾节点的前一个节点，即最后一个元素
  }

  iterator begin()
  {
    return iterator(head->next); // 返回指向第一个元素的迭代器
  }

  iterator end()
  {
    return iterator(tail); // 返回指向尾节点的迭代器
  }

  T &front()
  {
    return head->next->data; // 返回第一个元素的引用
  }

  T &back()
  {
    return tail->prev->data; // 返回最后一个元素的引用
  }

  size_t size() const
  {
    size_t count = 0;
    Node<T> *cur = head->next; // 从第一个元素开始
    while (cur != tail)        // 遍历链表直到尾节点
    {
      ++count;         // 计数器加1
      cur = cur->next; // 移动到下一个节点
    }
    return count; // 返回链表中元素的数量
  }

  // 删除指定值的元素
  void remove(const T &value)
  {
    Node<T> *cur = head->next; // 从第一个元素开始
    while (cur != tail)        // 遍历链表直到尾节点
    {
      if (cur->data == value) // 如果当前节点的值等于要删除的值
      {
        cur->prev->next = cur->next; // 将当前节点的前一个节点的下一个节点指向当前节点的下一个节点
        cur->next->prev = cur->prev; // 将当前节点的下一个节点的前一个节点指向当前节点的前一个节点
        Node<T> *temp = cur;         // 保存当前节点的指针
        cur = cur->next;             // 移动到下一个节点
        delete temp;                 // 删除当前节点
      }
      else
      {
        cur = cur->next; // 如果当前节点的值不等于要删除的值，继续移动到下一个节点
      }
    }
  }

  void clear()
  {
    Node<T> *cur = head->next; // 从第一个元素开始
    while (cur != tail)        // 遍历链表直到尾节点
    {
      Node<T> *temp = cur; // 保存当前节点的指针
      cur = cur->next;     // 移动到下一个节点
      delete temp;         // 删除当前节点
    }
    head->next = tail; // 重新连接头节点和尾节点
    tail->prev = head;
  }

private:
  Node<T> *head; // 指向链表头节点的指针,哨兵节点
  Node<T> *tail; // 指向链表尾节点的指针，哨兵节点
};

int main()
{
  MyList<int> mylist;

  mylist.push_back(10);
  mylist.push_back(20);
  mylist.push_back(30);
  mylist.push_front(40);

  for (const auto &item : mylist)
  {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  auto it = mylist.begin();
  std::advance(it, 2);   // 将迭代器移动到第三个元素
  mylist.insert(it, 25); // 第三个元素是 30，所以在 30 前插入 25

  for (const auto &item : mylist)
  {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  mylist.pop_front(); // 删除第一个元素
  mylist.remove(20);  // 删除值为 20 的元素
  for (const auto &item : mylist)
  {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  auto it2 = std::prev(mylist.end()); // 获取倒数第一个元素的迭代器
  mylist.erase(it2);                  // 删除倒数第一个元素

  for (const auto &item : mylist)
  {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  return 0;
}
```


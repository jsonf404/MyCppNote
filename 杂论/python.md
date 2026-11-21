#  python期末

## 2025Python考试题型

1. 单选（30分）

2. 填空题（读程序写运行结果24分，要求补充程序6分）

3. 论述题（20分）

4. 编程（20 分）

 

##  基本语法

标识符和命名规则，变量与赋值(python 的特殊性)、基本关键字及功能



###  标识符与命名规则

1. 只能由 **字母（A-Z / a-z）**、**数字（0-9）** 和 **下划线（_）** 组成。
2. 下划线开头有特殊含义：
   - `_name`：弱内部变量（约定俗成）
   - `__name`：类的私有变量（名称重整）
   - `__name__`：系统内置名称，勿随意使用



###  变量与赋值（Python 的特殊性）

> Python 的变量本质上是 **名字指向对象**，不是存储一个“值”。



1. **Python 的变量赋值机制：引用传递（指向对象）**

```python
a = 10
b = a
print(a, b)  # 10 10
```

此时 `a` 和 `b` 指向 **同一个对象 10**。

修改变量引用后：

```python
a = 20
print(a, b)  # 20 10
```

`a` 指向新的对象 20，`b` 仍然指向 10。



2. **可变对象与不可变对象**

- **不可变对象（无法原地修改）**：int, float, str, tuple(元组)，**意义就是赋值后改一个是不是都改。**
- **可变对象（可以原地修改）**：list（列表）, dict（字典）, set（集合）

```python
lst1 = [1,2,3]
lst2 = lst1
lst1.append(4)
print(lst1, lst2)  # 都变为 [1,2,3,4]
```

可变对象共享引用会互相影响。



3. **多变量赋值**

```python
a, b = 1, 2
x = y = z = 0  # 链式赋值
```



4. **变量类型可动态变化**

```python
x = 10
x = "hello" # 类型不固定
```





## 常用数据结构及方法

### 字符串

(1)字符串: 基本操作、字符串切片、格式化字符串、常用方法(如:len、max、min 和split等) 、字符串和列表的转换

#### 创建字符串

```python
# 单引号
str1 = 'Hello World'
# 双引号  
str2 = "Python Programming"
# 三引号（多行字符串）
str3 = '''这是一个
多行
字符串'''
```



#### 字符串访问

```python
text = "Python"

# 索引访问
print(text[0])    # 'P' - 第一个字符
print(text[-1])   # 'n' - 最后一个字符
print(text[2])    # 't' - 第三个字符

# 遍历字符串
for char in text:
    print(char)
```



#### 格式化字符串

```python
name = "Alice"
age = 25
score = 95.5

print(f"姓名: {name}, 年龄: {age}, 分数: {score}")
# 输出: 姓名: Alice, 年龄: 25, 分数: 95.5

# 表达式和格式化
print(f"明年年龄: {age + 1}")
print(f"分数: {score:.1f}")      # 保留1位小数
print(f"百分比: {score:.2%}")    # 百分比格式
```

---

```python
name = "Charlie"
age = 35

print("姓名: %s, 年龄: %d" % (name, age))
```



#### 常用方法

```python
text = "Python"
print(len(text))    # 6 - 字符串长度
print(max(text))    # 'y' - 最大字符(按ASCII)
print(min(text))    # 'P' - 最小字符(按ASCII)


text = "hello world hello python"
print(text.find("world"))     # 6 - 查找子串位置
print(text.count("hello"))    # 2 - 统计出现次数
print(text.replace("hello", "hi"))  # 'hi world hi python'
# 检查开头和结尾
print(text.startswith("hello"))  # True
print(text.endswith("python"))   # True
```



#### 字符串列表转换

```python
# 方法1: split() 按分隔符分割
text = "apple,banana,orange"
fruits_list = text.split(",")
print(fruits_list)  # ['apple', 'banana', 'orange']

# 方法2: list() 按字符分割
text = "hello"
char_list = list(text)
print(char_list)    # ['h', 'e', 'l', 'l', 'o']

# 方法3: 按特定规则分割
sentence = "This is a sample sentence"
words = sentence.split()  # 默认按空格分割
print(words)  # ['This', 'is', 'a', 'sample', 'sentence']
```



```python
# 方法1: join() 用指定字符连接
fruits = ['apple', 'banana', 'orange']
text1 = ",".join(fruits)
print(text1)  # 'apple,banana,orange'

text2 = " ".join(fruits)
print(text2)  # 'apple banana orange'

text3 = "".join(fruits)
print(text3)  # 'applebananaorange'

# 方法2: 使用字符串拼接
fruits = ['apple', 'banana', 'orange']
result = ""
for fruit in fruits:
    result += fruit + " "
result = result.strip()
print(result)  # 'apple banana orange'
```





### 元组（tuple）

**最重要的就是本身不可变，不能通过索引改变内部值，但如果内部值是可变类型，此时就是引用，直接改内部值也可以**

| 有序 | 不可变（和int等一样） | 允许重复 | 支持元素混合存储 |
| ---- | --------------------- | -------- | ---------------- |

```python
# 创建
# 方法1: 使用圆括号 (推荐)
tuple1 = (1, 2, 3, 4, 5)

# 方法2: 不使用括号 (元组打包)
tuple2 = 1, 2, 3, 4, 5

# 方法3: 创建单个元素的元组 (注意逗号!)
single_tuple = (42,)     # 这是一个元组
not_a_tuple = (42)       # 这只是一个整数 42

# 方法4: 创建空元组
empty_tuple = ()


# 访问
my_tuple = ('a', 'b', 'c', 'd', 'e')

print(my_tuple[0])   # 输出: 'a'
print(my_tuple[-1])  # 输出: 'e' (最后一个元素)

print(my_tuple[1:4]) # 输出: ('b', 'c', 'd')
print(my_tuple[:3])  # 输出: ('a', 'b', 'c')


# 常用操作
# 连接 +
tuple1 = (1, 2, 3)
tuple2 = (4, 5, 6)
combined = tuple1 + tuple2
print(combined)  # 输出: (1, 2, 3, 4, 5, 6)

# 重复 *
repeated = tuple1 * 3
print(repeated)  # 输出: (1, 2, 3, 1, 2, 3, 1, 2, 3)

# 成员检测 in
print(3 in tuple1)  # 输出: True
print(7 in tuple1)  # 输出: False

# 长度、最大值、最小值
print(len(my_tuple))     # 长度
print(max((1, 5, 3)))   # 最大值
print(min((1, 5, 3)))   # 最小值


# 多返回值
def f():
    return 1, 2, 3
a, b, c = f()		# 函数实际上返回元组 (1,2,3)。
```



### 列表和元组对比

> (2)列表与元组: 区别、转换、列表的元素操作、列表的切片、数值列表、排序、列表生成式

| 有序（插入顺序存储） | 允许重复 | 索引访问 |
| -------------------- | -------- | -------- |

#### **区别**

| 特性           | 列表                                | 元组                                           |
| :------------- | :---------------------------------- | :--------------------------------------------- |
| **语法**       | 方括号 `[]`                         | 圆括号 `()`                                    |
| **可变性**     | **可变**                            | **不可变**                                     |
| **性能**       | 较慢，占用更多内存                  | 更快，更省内存                                 |
| **用途**       | 存储需要**动态修改**的数据集合      | 存储**不应改变**的数据，如常量集、函数多返回值 |
| **作为字典键** | **不可以**（不可哈希）              | **可以**（可哈希）                             |
| **方法**       | 丰富 (`append`, `remove`, `sort`等) | 只有 `count()`, `index()`                      |



#### **相互转换**

```python
# 元组 → 列表
my_tuple = (1, 2, 3)
my_list = list(my_tuple)
print(my_list)   # 输出: [1, 2, 3]
print(type(my_list))  # <class 'list'>

# 列表 → 元组  
my_list = [4, 5, 6]
my_tuple = tuple(my_list)
print(my_tuple)  # 输出: (4, 5, 6)
print(type(my_tuple)) # <class 'tuple'>
```



#### 列表初始化

```python

```



#### **列表的元素操作**

```python
# 增
fruits = ['apple', 'banana']

fruits.append('orange')     # 末尾添加: ['apple', 'banana', 'orange']
fruits.insert(1, 'grape')   # 指定位置插入: ['apple', 'grape', 'banana', 'orange']
fruits.extend(['peach', 'kiwi']) # 合并列表: ['apple', 'grape', 'banana', 'orange', 'peach', 'kiwi']

# 删
fruits = ['apple', 'banana', 'orange', 'grape']
fruits.pop()           # 删除末尾: 'grape'，fruits变为['apple', 'banana', 'orange']
fruits.pop(1)          # 删除指定索引: 'banana'，fruits变为['apple', 'orange']
fruits.remove('apple') # 删除指定值: fruits变为['orange']
del fruits[0]          # 删除指定索引: fruits变为[]
# fruits.clear()       # 清空整个列表: []

# 查
fruits = ['apple', 'banana', 'orange', 'banana']
print(fruits.index('banana'))    # 返回第一个索引: 1
print(fruits.count('banana'))    # 出现次数: 2
print('apple' in fruits)         # 是否存在: True

# 改
fruits = ['apple', 'banana', 'orange']
fruits[1] = 'grape'    # 直接赋值: ['apple', 'grape', 'orange']
```



#### 列表的切片

> 切片是左含右不含

```python
numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

print(numbers[2:5])    # [2, 3, 4]     索引2到5(不含)
print(numbers[:4])     # [0, 1, 2, 3]  开始到索引4
print(numbers[6:])     # [6, 7, 8, 9]  索引6到末尾
print(numbers[::2])    # [0, 2, 4, 6, 8] 步长为2
print(numbers[::-1])   # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0] 反转列表

# 切片创建新列表，不影响原列表
new_list = numbers[1:4]
print(new_list)  # [1, 2, 3]
```



#### **数值列表**

```python
# 生成 0-4
numbers1 = list(range(5))           # [0, 1, 2, 3, 4]

# 生成 2-9
numbers2 = list(range(2, 10))       # [2, 3, 4, 5, 6, 7, 8, 9]

# 生成 1-9，步长为2
numbers3 = list(range(1, 10, 2))    # [1, 3, 5, 7, 9]


nums = [3, 1, 4, 1, 5, 9, 2]
print(min(nums))    # 最小值: 1
print(max(nums))    # 最大值: 9  
print(sum(nums))    # 求和: 25
```



#### **排序**

```python
1. 永久排序
fruits = ['orange', 'apple', 'banana']

fruits.sort()                    # 默认升序: ['apple', 'banana', 'orange']
fruits.sort(reverse=True)        # 降序: ['orange', 'banana', 'apple']

# 按字符串长度排序
fruits.sort(key=len)             # ['apple', 'orange', 'banana']


2. 临时排序
fruits = ['orange', 'apple', 'banana']
sorted_fruits = sorted(fruits)   # 返回新列表: ['apple', 'banana', 'orange']
print(fruits)                    # 原列表不变: ['orange', 'apple', 'banana']


3. 反转
fruits = ['apple', 'banana', 'orange']
fruits.reverse()                 # 永久反转: ['orange', 'banana', 'apple']
```



#### **列表生成式**

> 简洁高效地创建列表的方法

```python
# 1. 简单生成式
squares = [x**2 for x in range(5)]           # 计算x（1-5）的平方：[0, 1, 4, 9, 16]

# 2. 带条件的生成式
even_squares = [x**2 for x in range(10) if x % 2 == 0]  # [0, 4, 16, 36, 64]

# 3. 对元素进行处理
fruits = ['apple', 'banana', 'orange']
upper_fruits = [fruit.upper() for fruit in fruits]  # ['APPLE', 'BANANA', 'ORANGE']

# 4. 多重循环
pairs = [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]  # [(1,3),(1,4),(2,3),(2,1)...]
```

 

### 字典（dict）

> (3)字典: 创建和访问、字典基本操作方法、字典排序方法(key、value)

| 键值对 | 无序 | 键值是不可变类型 | 键唯一 |
| ------ | ---- | ---------------- | ------ |

#### **创建字典**

```python
# 方法1: 花括号 {}
person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}
print(person)  # {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 方法2: dict() 函数
person2 = dict(name='Bob', age=30, city='Shanghai')
print(person2) # {'name': 'Bob', 'age': 30, 'city': 'Shanghai'}

# 方法3: 从键值对列表创建
person3 = dict([('name', 'Charlie'), ('age', 35), ('city', 'Guangzhou')])
print(person3) # {'name': 'Charlie', 'age': 35, 'city': 'Guangzhou'}

# 空字典
empty_dict = {}
empty_dict2 = dict()
```



#### **访问字典**

```python
person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

# 方法1: 方括号 [] (键不存在会报错)
print(person['name'])   # 'Alice'

# 方法2: get() 方法 (键不存在返回None或默认值)
print(person.get('name'))      # 'Alice'
print(person.get('gender'))    # None
print(person.get('gender', '未知'))  # '未知'

# 方法3: 检查键是否存在
print('name' in person)    # True
print('gender' in person)  # False
```



#### **基本操作**

```python
# 增
person = {'name': 'Alice', 'age': 25}
person['city'] = 'Beijing'        # {'name': 'Alice', 'age': 25, 'city': 'Beijing'}
person['age'] = 26               # {'name': 'Alice', 'age': 26, 'city': 'Beijing'}

# update() 批量更新
person.update({'age': 27, 'gender': 'female'})  
# {'name': 'Alice', 'age': 27, 'city': 'Beijing', 'gender': 'female'}


# 删
person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

del person['age']                # 删除键 'age'
print(person)                    # {'name': 'Alice', 'city': 'Beijing'}

city = person.pop('city')        # 删除 'city' 并返回其值
print(city)                      # 'Beijing'
print(person)                    # {'name': 'Alice'}

# popitem() 删除最后插入的键值对
person['age'] = 25
person['city'] = 'Beijing'
last_item = person.popitem()     # 删除 ('city', 'Beijing')
print(last_item)                 # ('city', 'Beijing')

person.clear()                   # {}


# 查
person = {'name': 'Alice', 'age': 25, 'city': 'Beijing'}

print(person.keys())     # dict_keys(['name', 'age', 'city'])
print(person.values())   # dict_values(['Alice', 25, 'Beijing'])
print(person.items())    # dict_items([('name', 'Alice'), ('age', 25), ('city', 'Beijing')])

# 字典长度
print(len(person))       # 3

# 遍历字典
for key in person:
    print(f"{key}: {person[key]}")

for key, value in person.items():
    print(f"{key}: {value}")
```



#### 字典排序

> 没有永久排序 `sort`

```python
# 按键排序
sorted_dict = dict(sorted(原字典.items()))

# 按值排序
sorted_dict = dict(sorted(原字典.items(), key=lambda x: x[1]))

# 降序排列（加 reverse=True）
sorted_dict = dict(sorted(原字典.items(), reverse=True))
```





### 集合（set）

> (4)集合: 集合基本操作、利用集合来去除字典中的重复元素

| 无序 | 元素不可重复 | 元素是不可变类型 |
| ---- | ------------ | ---------------- |

#### 创建集合

```python
# 方法1: 花括号 {} (不能创建空集合)
set1 = {1, 2, 3, 4, 5}
print(set1)  # {1, 2, 3, 4, 5}

# 方法2: set() 函数 (可以创建空集合)
set2 = set([1, 2, 2, 3, 3, 4])  # 自动去重
print(set2)  # {1, 2, 3, 4}

empty_set = set()  # 空集合
print(empty_set)   # set()

# 注意: {} 创建的是空字典，不是空集合
empty_dict = {}
print(type(empty_dict))  # <class 'dict'>
```



#### 基本操作

```python
# 添加元素
fruits = {'apple', 'banana'}
fruits.add('orange')
print(fruits)  # {'apple', 'banana', 'orange'}

fruits.update(['grape', 'kiwi'])  # 添加多个元素
print(fruits)  # {'apple', 'banana', 'orange', 'grape', 'kiwi'}


# 删除元素
fruits.remove('banana')  # 删除存在的元素
print(fruits)  # {'apple', 'orange', 'grape', 'kiwi'}

# fruits.remove('pear')  # 删除不存在的元素会报错

fruits.discard('kiwi')   # 删除元素，不存在也不报错
fruits.discard('pear')   # 不会报错

popped = fruits.pop()    # 随机删除一个元素并返回
print(popped)           # 随机的一个水果名
```



#### 集合运算

```python
A = {1, 2, 3, 4, 5}
B = {4, 5, 6, 7, 8}

# 并集
print(A | B)        # {1, 2, 3, 4, 5, 6, 7, 8}

# 交集
print(A & B)        # {4, 5}

# 差集 (在A中但不在B中)
print(A - B)        # {1, 2, 3}

# 对称差集 (只在A或只在B中) 
print(A ^ B)        # {1, 2, 3, 6, 7, 8}
```



#### 去除字典重复

1. **去掉重复值**

```python
# 原字典：不同的键有相同的值
data = {'a': 100, 'b': 200, 'c': 100, 'd': 300, 'e': 200}

# 去重方法：保留每个值的第一个键
seen_values = set()
result = {}

for key, value in data.items():
    if value not in seen_values:
        result[key] = value
        seen_values.add(value)

print(result)
# 输出: {'a': 100, 'b': 200, 'd': 300}
```

 

2. **去掉值内重复的值**

```python
# 简洁的字典推导式写法
scores =
{
    'math': [85, 90, 85, 78, 90],
    'english': [88, 88, 76, 90, 76]
}

clean_scores = {subject: list(set(score_list)) 
                for subject, score_list in scores.items()}

print(clean_scores)
# 输出: {'math': [85, 90, 78], 'english': [88, 76, 90]}
```





### 三者区别

| 特性         | List         | Dict                         | Set                |
| :----------- | :----------- | :--------------------------- | :----------------- |
| **有序性**   | ✅ 有序       | ✅ 存疑，现代有序，旧版无序   | ❌ 无序             |
| **可变性**   | ✅ 可变       | ✅ 可变                       | ✅ 可变             |
| **元素要求** | 任何类型     | 键：不可变类型，值：任何类型 | 不可变类型         |
| **重复元素** | ✅ 允许       | 键：❌ 不允许，值：✅ 允许     | ❌ 不允许           |
| **访问方式** | 索引 `[0]`   | 键 `[key]`                   | 只能遍历或成员检测 |
| **主要用途** | 有序数据集合 | 键值对映射                   | 去重、集合运算     |





##  函数

### 函数的定义和使用

1. **默认参数**

```python
def power(base, exponent=2):
    """计算幂，默认指数为2（平方）"""
    return base ** exponent

print(power(3))      # 输出: 9 (3的平方)
print(power(3, 3))   # 输出: 27 (3的立方)
```



2. **关键字参数**

```python
def introduce(name, age, city):
    """自我介绍"""
    print(f"我叫{name}，今年{age}岁，来自{city}")

# 使用关键字参数，顺序可以改变
introduce(age=25, city="北京", name="张三")
```



3. **返回多值，本质是元组**

```python
def calculate(x, y):
    """返回和、差、积、商"""
    add = x + y
    subtract = x - y
    multiply = x * y
    divide = x / y if y != 0 else None
    return add, subtract, multiply, divide

# 接收多个返回值
a, b, c, d = calculate(10, 2)
print(f"和: {a}, 差: {b}, 积: {c}, 商: {d}")
```



### 变量的作用域

1. **全局 ＞ 闭包 ＞ 局部** ，只能小的访问大的
2.  **访问不用关键字，修改需要关键字：全局(global)、闭包（nonlocal）**

```python
# global 示例
global_var = "global"

def test_global():
    global global_var
    global_var = "modified global"

# nonlocal 示例
def test_nonlocal():
    enclosing_var = "enclosing"
    
    def inner():
        nonlocal enclosing_var
        enclosing_var = "modified enclosing"
    
    inner()
    return enclosing_var

test_global()
print(global_var)  # modified global

result = test_nonlocal()
print(result)      # modified enclosing
```



### 函数参数

> 函数参数的类型:形参、实参；参数传递方式

1. **注意混合使用**

```python
def student_info(name, age, grade, school="第一中学"):
    """学生信息（混合参数）"""
    print(f"姓名: {name}, 年龄: {age}, 年级: {grade}, 学校: {school}")

# 位置参数 + 关键字参数
student_info("小刚", 16, school="实验中学", grade="高一")
# 注意：位置参数必须在关键字参数之前！
```



2. **可变参数**

```python
# *args 接收任意数量的位置参数，本质是tuple
def sum_all(*args):
    """计算所有参数的和"""
    total = 0
    for num in args:
        total += num
    return total

print(sum_all(1, 2, 3))        # 输出: 6
print(sum_all(1, 2, 3, 4, 5))  # 输出: 15


# **kwargs 接收任意数量的关键字参数，本质上dict
def print_info(**kwargs):
    """打印所有关键字参数"""
    for key, value in kwargs.items():
        print(f"{key}: {value}")

print_info(name="Alice", age=30, city="New York") # 循环打印
```



### 函数式编程

> 函数式编程: 高阶函数（filter等）、lambda函数、闭包

#### 高阶函数

> 高阶函数是指可以接受其他函数作为参数，或者返回函数作为结果的函数。

1. **map函数 - 用于数据转换，把可迭代对象每一个都运用一个函数**

```python
map(function, iterable, ...)
```

---

```python
numbers = [1, 2, 3, 4, 5]
# 将每个元素平方
squared = list(map(lambda x: x**2, numbers))
print(squared)  # [1, 4, 9, 16, 25]

# 使用普通函数
def to_upper(text):
    return text.upper()

words = ['hello', 'world', 'python']
upper_words = list(map(to_upper, words))
print(upper_words)  # ['HELLO', 'WORLD', 'PYTHON']

# 多个可迭代对象
a = [1, 2, 3]
b = [10, 20, 30]
result = list(map(lambda x, y: x + y, a, b))
print(result)  # [11, 22, 33]
```



2.  **filter函数 - 数据过滤返回满足条件的元素**

```python
filter(function, iterable)
```

---

```python
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 过滤偶数
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)  # [2, 4, 6, 8, 10]

# 过滤非空字符串
words = ['hello', '', 'world', '', 'python', '']
non_empty = list(filter(None, words))  # None表示过滤掉False值
print(non_empty)  # ['hello', 'world', 'python']

# 使用普通函数过滤
def is_positive(n):
    return n > 0

mixed_numbers = [-5, -2, 0, 3, 8, -1]
positive_numbers = list(filter(is_positive, mixed_numbers))
print(positive_numbers)  # [3, 8]
```



3. **reduce函数 - 数据聚合，对数据进行累计计算，返回单个值**

```python
from functools import reduce

# reduce(function, iterable[, initial])
numbers = [1, 2, 3, 4, 5]

# 计算累加和
total = reduce(lambda x, y: x + y, numbers)
print(total)  # 15

# 计算阶乘
factorial = reduce(lambda x, y: x * y, range(1, 6))
print(factorial)  # 120

# 使用初始值
result = reduce(lambda x, y: x + y, numbers, 10)
print(result)  # 25 (10 + 1 + 2 + 3 + 4 + 5)

# 找出最大值
max_value = reduce(lambda x, y: x if x > y else y, numbers)
print(max_value)  # 5
```



4. **sorted函数 - 排序**

```python
sorted(iterable, key=None, reverse=False)
```

---

```python
students = [
    {'name': 'Alice', 'score': 85},
    {'name': 'Bob', 'score': 92},
    {'name': 'Charlie', 'score': 78}
]

# 按分数排序
sorted_students = sorted(students, key=lambda x: x['score'])
print(sorted_students)
# [{'name': 'Charlie', 'score': 78}, {'name': 'Alice', 'score': 85}, {'name': 'Bob', 'score': 92}]

# 按姓名长度排序
names = ['Alice', 'Bob', 'Charlie', 'David']
sorted_names = sorted(names, key=len)
print(sorted_names)  # ['Bob', 'Alice', 'David', 'Charlie']

# 多级排序
data = [('apple', 3), ('banana', 2), ('apple', 1), ('banana', 4)]
sorted_data = sorted(data, key=lambda x: (x[0], x[1]))
print(sorted_data)  # [('apple', 1), ('apple', 3), ('banana', 2), ('banana', 4)]
```



#### lambda表达式

> Lambda函数是匿名函数，用于创建简单的、一次性的函数对象。

1. **基本语法**

```python
# lambda 参数: 表达式
add = lambda x, y: x + y
print(add(3, 5))  # 8

# 等同于普通函数
def add(x, y):
    return x + y
```



#### 闭包

```python
# 1. 计数器
def create_counter():
    count = 0
    
    def counter():
        nonlocal count  # 声明使用外部变量
        count += 1
        return count
    
    return counter

# 使用计数器
counter1 = create_counter()
print(counter1())  # 1
print(counter1())  # 2
print(counter1())  # 3

counter2 = create_counter()  # 新的独立计数器
print(counter2())  # 1
```



## 文件与异常

(1)文件操作open\read\readline\readlines\write\writelines

### open

| 模式  | 描述                             |
| :---- | :------------------------------- |
| `'r'` | 只读（默认）                     |
| `'w'` | 写入，会覆盖已有文件             |
| `'a'` | 追加，在文件末尾添加             |
| `'x'` | 创建新文件，如果文件已存在则报错 |
| `'b'` | 二进制模式                       |
| `'t'` | 文本模式（默认）                 |
| `'+'` | 读写模式                         |

```python
# 4. 读写模式
file = open('example.txt', 'r+', encoding='utf-8')

# 5. 推荐使用 with 语句，自动关闭文件
with open('example.txt', 'r', encoding='utf-8') as file:
    content = file.read()
# 文件会自动关闭
```



### read

```python
# 读取整个文件内容
with open('example.txt', 'r', encoding='utf-8') as file:
    content = file.read()
    print(content)

# 读取指定字节数
with open('example.txt', 'r', encoding='utf-8') as file:
    first_100_chars = file.read(100)  # 读取前100个字符
    print(first_100_chars)
```



### readline

> 逐行读取

```python
# 读取一行
with open('example.txt', 'r', encoding='utf-8') as file:
    first_line = file.readline()
    print(f"第一行: {first_line}")
    
    second_line = file.readline()
    print(f"第二行: {second_line}")

# 逐行读取整个文件
with open('example.txt', 'r', encoding='utf-8') as file:
    line = file.readline()
    while line:
        print(line.strip())  # strip() 去除换行符
        line = file.readline()
```



### readlines

> 读取所有行

```python
# 读取所有行到列表中
with open('example.txt', 'r', encoding='utf-8') as file:
    lines = file.readlines()
    print(f"总行数: {len(lines)}")
    
    for i, line in enumerate(lines, 1):  # 从1开始计数
        print(f"第{i}行: {line.strip()}")
```



### write

```python
# 写入单个字符串
with open('output.txt', 'w', encoding='utf-8') as file:
    file.write("Hello, World!\n")
    file.write("这是第二行\n")

# 写入多个内容
lines_to_write = ["第一行\n", "第二行\n", "第三行\n"]
with open('output.txt', 'w', encoding='utf-8') as file:
    for line in lines_to_write:
        file.write(line)
```



### writelines

> 全写入

```python
# 写入字符串列表
lines = ["第一行\n", "第二行\n", "第三行\n"]

with open('example.txt', 'w', encoding='utf-8') as file:
    file.writelines(lines)  # 写入整个列表

# 输出文件内容：
# 第一行
# 第二行
# 第三行
```



### 异常处理

> (2)异常和异常处理

| 异常类型              | 触发场景   | 示例代码                                                     |
| :-------------------- | :--------- | :----------------------------------------------------------- |
| **ZeroDivisionError** | 除数为零   | `result = 10 / 0`                                            |
| **TypeError**         | 类型不匹配 | `result = "hello" + 5`                                       |
| **ValueError**        | 值不合法   | `number = int("abc")`                                        |
| **IndexError**        | 索引越界   | `lst = [1, 2, 3]` `item = lst[5]`                            |
| **KeyError**          | 键不存在   | `dct = {'a': 1}` `value = dct['b']`                          |
| **FileNotFoundError** | 文件不存在 | `with open('nonexistent.txt', 'r') as f:` `content = f.read()` |
| **AttributeError**    | 属性不存在 | `text = "hello"` `text.append("world")`                      |



1. **基本示例**

```python
try:
    number = int(input("请输入一个数字: "))
    result = 100 / number
    print(f"100 / {number} = {result}")
except ValueError:
    print("错误：请输入有效的数字！")
except ZeroDivisionError:
    print("错误：不能除以零！")
```



2. **完整示例：**

```python
try:
    # 尝试执行的代码
    result = 10 / 2
except ZeroDivisionError:
    # 发生特定异常时执行
    print("除零错误！")
else:
    # 没有异常时执行
    print(f"计算成功，结果是: {result}")
finally:
    # 无论是否发生异常都会执行
    print("计算完成")
```



3. **获取异常信息和类型**

```python
try:
    number = int("abc")
except ValueError as e:
    print(f"错误信息: {e}")
    print(f"错误类型: {type(e).__name__}")

# 输出:
# 错误信息: invalid literal for int() with base 10: 'abc'
# 错误类型: ValueError
```



## 面向对象

### class

> (1)class的基本概念

```python
class Student:
    # 类属性
    school = "第一中学"
    student_count = 0
    
    # 类似构造函数
    def __init__(self, name, age):
        # 实例属性
        self.name = name
        self.age = age
        Student.student_count += 1
    
    def study(self, subject):
        """实例方法"""
        return f"{self.name}正在学习{subject}"
    
    @classmethod
    def get_school_info(cls):
        """类方法"""
        return f"学校：{cls.school}，学生总数：{cls.student_count}"
    
    @staticmethod
    def is_adult(age):
        """静态方法"""
        return age >= 18
```



### 封装

```python
class BankAccount:
    def __init__(self, account_holder, balance=0):
        self.account_holder = account_holder
        self.__balance = balance  # 私有属性
    
    # 公有方法访问私有属性
    def get_balance(self):
        return self.__balance
    
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
            return True
        return False
    
    def withdraw(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount
            return True
        return False
    
    # 私有方法
    def __validate_amount(self, amount):
        return isinstance(amount, (int, float)) and amount > 0

# 使用封装
account = BankAccount("张三", 1000)
print(account.get_balance())  # 1000
account.deposit(500)
print(account.get_balance())  # 1500

# 无法直接访问私有属性
# print(account.__balance)  # 错误！
```



### 继承

1. **单继承**

```python
# 父类（基类）
class Animal:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def eat(self):
        return f"{self.name}在吃东西"
    
    def sleep(self):
        return f"{self.name}在睡觉"
    
    def make_sound(self):
        return "动物发出声音"

# 子类（派生类）
class Dog(Animal):  # Dog 继承 Animal
    def __init__(self, name, age, breed):
        super().__init__(name, age)  # 调用父类构造方法
        self.breed = breed  # 子类特有属性
    
    # 方法重写（Override）
    def make_sound(self):
        return f"{self.name}汪汪叫"
    
    # 子类特有方法
    def fetch(self):
        return f"{self.name}在接飞盘"

# 使用继承
my_dog = Dog("小黑", 3, "拉布拉多")
print(my_dog.eat())        # 小黑在吃东西 ← 继承自父类
print(my_dog.sleep())      # 小黑在睡觉   ← 继承自父类  
print(my_dog.make_sound()) # 小黑汪汪叫   ← 重写的方法
print(my_dog.fetch())      # 小黑在接飞盘 ← 子类特有方法
```



2. **多继承**

```python
class Flyable:
    def fly(self):
        return "能够飞行"
    
    def take_off(self):
        return "起飞中..."

class Swimmable:
    def swim(self):
        return "能够游泳"
    
    def dive(self):
        return "潜入水中"

class Duck(Flyable, Swimmable):  # 多继承
    def __init__(self, name):
        self.name = name
    
    def quack(self):
        return f"{self.name}嘎嘎叫"

# 使用多继承
duck = Duck("唐老鸭")
print(duck.fly())      # 能够飞行   ← 来自Flyable
print(duck.swim())     # 能够游泳   ← 来自Swimmable  
print(duck.take_off()) # 起飞中... ← 来自Flyable
print(duck.quack())    # 唐老鸭嘎嘎叫 ← 自己特有
```



3. **扩展式重写**

```python
class Phone:
    def __init__(self, brand, price):
        self.brand = brand
        self.price = price
    
    def call(self, number):
        return f"{self.brand}正在拨打{number}"
    
    def get_info(self):
        return f"品牌：{self.brand}，价格：{self.price}"

class SmartPhone(Phone):
    def __init__(self, brand, price, os):
        super().__init__(brand, price)
        self.os = os
    
    # 扩展父类方法
    def call(self, number):
        # 先调用父类方法
        base_result = super().call(number)
        # 再添加新功能
        return base_result + f" [视频通话]"
    
    # 重写并扩展信息方法
    def get_info(self):
        base_info = super().get_info()
        return base_info + f"，操作系统：{self.os}"

# 使用
phone = Phone("诺基亚", 500)
smart_phone = SmartPhone("苹果", 6000, "iOS")

print(phone.call("123456789"))      # 诺基亚正在拨打123456789
print(smart_phone.call("123456789")) # 苹果正在拨打123456789 [视频通话]
print(smart_phone.get_info())       # 品牌：苹果，价格：6000，操作系统：iOS
```



### 多态

1. **正常多态**

```python
class Shape:
    def area(self):
        """计算面积 - 抽象方法"""
        raise NotImplementedError("子类必须实现area方法")

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    
    def area(self):
        return 3.14159 * self.radius ** 2

class Triangle(Shape):
    def __init__(self, base, height):
        self.base = base
        self.height = height
    
    def area(self):
        return 0.5 * self.base * self.height

# 多态使用
def calculate_total_area(shapes):
    """计算所有形状的总面积"""
    total = 0
    for shape in shapes:
        total += shape.area()  # 同样的方法调用，不同的实现
    return total

# 测试
shapes = [
    Rectangle(10, 5),
    Circle(7),
    Triangle(6, 8)
]

total_area = calculate_total_area(shapes)
print(f"总面积: {total_area:.2f}")  # 总面积: 252.94
```



2. **鸭子多态**

```python
# 不需要继承同一父类，只要具有相同接口即可
class PDFExporter:
    def export(self, data):
        return f"导出PDF: {data}"

class ExcelExporter:
    def export(self, data):
        return f"导出Excel: {data}"

class CSVExporter:
    def export(self, data):
        return f"导出CSV: {data}"

def export_data(exporter, data):
    """导出数据 - 鸭子类型多态"""
    return exporter.export(data)

# 使用
exporters = [PDFExporter(), ExcelExporter(), CSVExporter()]
data = "销售报告"

for exporter in exporters:
    print(export_data(exporter, data))
# 输出:
# 导出PDF: 销售报告
# 导出Excel: 销售报告  
# 导出CSV: 销售报告
```



3. **抽象类**

```python
from abc import ABC, abstractmethod

class Animal(ABC):  # 继承ABC表示这是抽象类
    @abstractmethod
    def speak(self):
        """动物叫的方法 - 子类必须实现"""
        pass
    
    @abstractmethod
    def move(self):
        """动物移动的方法 - 子类必须实现"""
        pass

class Dog(Animal):
    def speak(self):  # 必须实现抽象方法
        return "汪汪！"
    
    def move(self):   # 必须实现抽象方法
        return "用四条腿跑"

class Cat(Animal):
    def speak(self):
        return "喵喵！"
    
    def move(self):
        return "悄悄地走"

# 使用
dog = Dog()
cat = Cat()

print(dog.speak())  # 汪汪！
print(cat.speak())  # 喵喵！
print(dog.move())   # 用四条腿跑

# 不能直接创建抽象类的实例
# animal = Animal()  # 报错：TypeError
```



### 对象成员和方法

1. 实例级别，对象成员就是在 `__init__` 里面的有访问权限的东西
2. 对象方法就是类函数，操作对象成员



### 类成员和方法

1. 类成员和类方法就是属于类的，**所有对象共享**
2. 加上 **`@classmethod`** 声明

```python
class Student:
    # 类成员（类变量） - 所有对象共享
    school = "清华大学"
    student_count = 0
    
    def __init__(self, name, age):
        # 对象成员
        self.name = name
        self.age = age
        # 修改类成员
        Student.student_count += 1
    
    # 对象方法
    def study(self):
        return f"{self.name}在学习"
    
    # 类方法 - 操作类成员
    @classmethod
    def get_school_info(cls):
        return f"学校: {cls.school}, 学生总数: {cls.student_count}"
    
    @classmethod
    def change_school(cls, new_school):
        cls.school = new_school
        return f"学校已更改为: {new_school}"
    
    # 类方法作为工厂方法
    @classmethod
    def create_graduate_student(cls, name, age):
        return cls(name, age)  # 创建对象

# 使用类成员和方法
print(Student.get_school_info())  # 学校: 清华大学, 学生总数: 0

student1 = Student("张三", 20)
student2 = Student("李四", 22)

print(Student.get_school_info())  # 学校: 清华大学, 学生总数: 2

# 修改类成员影响所有对象
Student.change_school("北京大学")
print(Student.get_school_info())  # 学校: 北京大学, 学生总数: 2
print(student1.school)  # 北京大学
print(student2.school)  # 北京大学

# 通过类方法创建对象
grad_student = Student.create_graduate_student("王五", 25)
print(grad_student.get_info())  # 学生: 王五, 年龄: 25, 平均分: 0.0
```



### 静态成员和方法

1. **`@staticmethod`** 声明

```python
class MathUtils:
    # 静态成员（常量） - 与具体对象无关
    PI = 3.14159
    E = 2.71828
    VERSION = "1.0.0"
    
    # 静态方法 - 工具函数，不依赖类或对象状态
    @staticmethod
    def add(a, b):
        return a + b
    
    @staticmethod
    def multiply(a, b):
        return a * b
    
    @staticmethod
    def circle_area(radius):
        return MathUtils.PI * radius ** 2
    
    @staticmethod
    def is_even(number):
        return number % 2 == 0
    
    @staticmethod
    def get_version():
        return f"版本: {MathUtils.VERSION}"

# 使用静态成员和方法 - 不需要创建对象
print(MathUtils.PI)                    # 3.14159
print(MathUtils.add(5, 3))             # 8
print(MathUtils.multiply(4, 7))        # 28
print(MathUtils.circle_area(5))        # 78.53975
print(MathUtils.is_even(10))           # True
print(MathUtils.get_version())         # 版本: 1.0.0

# 也可以通过对象使用（但不推荐）
utils = MathUtils()
print(utils.add(2, 3))  # 5
```



### Python 的动态特性

1. **动态添加属性和方法**

```python
class Student:
    def __init__(self, name):
        self.name = name

# 创建对象
student = Student("李四")

# 动态添加类属性
Student.school = "清华大学"

# 动态添加类方法
@classmethod
def get_school(cls):
    return cls.school

Student.get_school = get_school

# 动态添加实例方法
def study(self, subject):
    return f"{self.name}在学习{subject}"

Student.study = study

# 使用动态添加的成员
print(student.school)          # 清华大学
print(Student.get_school())    # 清华大学
print(student.study("数学"))    # 李四在学习数学
```





## 基本库的了解

### Random

> 生成随机数

```python
import random

# 1. 基本随机数
print(random.random())          # [0.0, 1.0) 的随机浮点数
print(random.uniform(1, 10))    # [1, 10] 的随机浮点数
print(random.randint(1, 100))   # [1, 100] 的随机整数

# 2. 序列操作
fruits = ['apple', 'banana', 'orange', 'grape']
print(random.choice(fruits))    # 随机选择一个元素
print(random.sample(fruits, 2)) # 随机选择2个不重复元素
random.shuffle(fruits)          # 打乱列表顺序
print(fruits)

# 3. 正态分布
print(random.gauss(0, 1))       # 均值为0，标准差为1的正态分布
```



### os

> 操作系统接口

```python
import os

# 1. 路径操作
print(os.getcwd())              # 当前工作目录
print(os.listdir('.'))          # 列出当前目录文件

# 2. 文件操作
os.makedirs('test_dir/sub_dir', exist_ok=True)  # 创建目录
print(os.path.exists('test_dir'))               # 检查路径是否存在
print(os.path.isdir('test_dir'))                # 检查是否是目录
print(os.path.isfile('test.py'))                # 检查是否是文件

# 3. 路径拼接和分解
file_path = os.path.join('folder', 'subfolder', 'file.txt')
print(file_path)  # folder/subfolder/file.txt

dirname, filename = os.path.split(file_path)
print(f"目录: {dirname}, 文件名: {filename}")

name, ext = os.path.splitext(filename)
print(f"文件名: {name}, 扩展名: {ext}")
```



### Math

```python
import math

# 1. 数值运算
print(math.sqrt(16))            # 平方根: 4.0
print(math.pow(2, 3))           # 幂运算: 8.0
print(math.exp(1))              # e的1次方: 2.718...
print(math.log(100, 10))        # 对数: 2.0

# 2. 三角函数
angle = math.radians(45)        # 角度转弧度
print(math.sin(angle))          # 正弦值
print(math.cos(angle))          # 余弦值
print(math.tan(angle))          # 正切值

# 3. 数值处理
print(math.ceil(4.2))           # 向上取整: 5
print(math.floor(4.8))          # 向下取整: 4
print(math.fabs(-5.5))          # 绝对值: 5.5
print(round(3.14159, 2))        # 四舍五入: 3.14
```



### Time

```python
import time

# 1. 时间戳
print(time.time())              # 当前时间戳（秒）

# 2. 结构化时间
current_time = time.localtime() # 本地时间
print(f"年份: {current_time.tm_year}")
print(f"月份: {current_time.tm_mon}")
print(f"日期: {current_time.tm_mday}")
print(f"小时: {current_time.tm_hour}")

# 3. 时间格式化
print(time.strftime("%Y-%m-%d %H:%M:%S"))  # 2024-01-15 14:30:25
print(time.strftime("%A, %B %d"))          # Monday, January 15

# 4. 时间解析
time_str = "2024-01-15 14:30:00"
parsed_time = time.strptime(time_str, "%Y-%m-%d %H:%M:%S")
print(parsed_time)
```



### Jieba

> 自然语言处理

```python
import jieba

text = "我爱自然语言处理技术"

# 1. 精确模式
words = jieba.cut(text, cut_all=False)
print("精确模式:", "/".join(words))  # 我/爱/自然语言/处理/技术

# 2. 全模式
words = jieba.cut(text, cut_all=True)
print("全模式:", "/".join(words))    # 我/爱/自然/自然语言/语言/处理/技术

# 3. 搜索引擎模式
words = jieba.cut_for_search(text)
print("搜索引擎模式:", "/".join(words))  # 我/爱/自然/语言/自然语言/处理/技术

# 4. 提取关键词
import jieba.analyse
text_long = "机器学习是人工智能的重要分支，深度学习是机器学习的一种方法"
keywords = jieba.analyse.extract_tags(text_long, topK=3)
print("关键词:", keywords)  # ['机器学习', '深度', '学习']
```



### Matplotlib

> 数据可视化，图表等

```python
import matplotlib.pyplot as plt
import numpy as np

# 1. 简单折线图
x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

plt.figure(figsize=(8, 4))
plt.plot(x, y, 'ro-', linewidth=2, markersize=8, label='数据线')
plt.title('简单折线图')
plt.xlabel('X轴')
plt.ylabel('Y轴')
plt.legend()
plt.grid(True)
plt.show()

# 2. 散点图
x = np.random.randn(100)
y = np.random.randn(100)
colors = np.random.rand(100)
sizes = 100 * np.random.rand(100)

plt.scatter(x, y, c=colors, s=sizes, alpha=0.5)
plt.title('散点图')
plt.show()
```



## 爬虫

理解爬虫的基本原理与处理过程

### 工作流程：

```bash
开始 → 获取URL → 下载网页 → 解析内容 → 提取数据 → 存储数据 → 获取新URL → 结束
```


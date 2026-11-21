# JS基础

## JS插件

[swiper官网](https://www.swiper.com.cn/)

[在线演示视频](https://www.swiper.com.cn/demo/index.html)

[基本使用流程](https://www.swiper.com.cn/usage/index.html)

[查看API文档，配置插件](https://www.swiper.com.cn/api/index.html)





作用：**实现人机交互**

- 网页特效
- 表单验证
- 数据交互，后端数据渲染到前端

~~~mermaid
graph 
JavaScript-->ECMAScript
JavaScript-->WebAPIs
WebAPIs-->DOM
WebAPIs-->BOM
~~~



## 引入方式

### 内部方式

**在<body>里面用<script>包裹即可**

~~~html
<body>
    <script>
        alert('你好，js');
        // alert 页面弹出警示框
    </script>
</body>
~~~



### 外部方式

代码独立写在.js结尾的文件，再用`src`引入

~~~html
<body>
    <script src="my.js"></script>
    //此标签内部的代码会被无视
</body>
~~~



## 输入输出

### 输出

1. 作用：向body里面输出内容，可以用标签语法

~~~html
<body>
    <script>
        document.write('<h1>输出内容</h1>')
    </script>
</body>
~~~



2. 作用：页面弹出警示框

~~~HTML
<body>
    <script>
        alert('警示框')
    </script>
</body>
~~~



3. 控制台输出，调试使用

~~~html
<body>
    <script>
        console.log('控制台输出')
    </script>
</body>
~~~



### 输入

1. 弹窗形式提醒输入

~~~html
<body>
    <script>
        prompt('请输入内容')
    </script>
</body>
~~~



## 数据类型

js中变量值决定了其数据类型,使用typeof检查

~~~html
<body>
  	<script> 
    	// 检测 1 是什么类型数据，结果为 number
    	document.write(typeof 1)
  	</script>
</body>
~~~



### 变量

使用`let`关键字来声明变量

~~~html
<body>
    <script>
        // 输入的密码存储在num中
        let num = prompt('请输入密码')
        alert('你的密码是')
        // 再通过document输出
        document.write(num)
    </script>
</body>
~~~



### 常量

用const声明，永远不会改变

~~~
<body>
    <script>
        const PI = 3.14
    </script>
</body>
~~~



### 模板字符串

可以使用类似于string的加法，也可以如下方式

~~~ html
<body>
    <script>
        let age = 20
        document.write(`我${age}岁了`)
    </script>
</body>
~~~



## 对象

### 定义

obejct,类似于结构体。

增删查改也类似于结构体，`.`引用即可

```html
let obj = {
	uname:'AAA',
	age:18,
	genter:boy
}
```



查的两种方法：

~~~html
console.log(obj.uname)

console.log(obj['umane'])
~~~



### 对象内函数

~~~html
 <script>
        let obj = {
            all: function (x, y) {
                console.log(x + y)
            }
        }

        obj.all(10, 10)

</script>
~~~



### 遍历对象内容

~~~html
    <script>
        let obj = {
            uname: 'AAA',
            age: 18,
            gender: 'man'
        }

        for (let k in obj) {
            // 此时输出对象的三个属性名，k===‘uname’
            console.log(k)
            // 此时输出属性名对应的内容
            console.log(obj[k])
        }
    </script>
~~~



## 数组中map方法

map可以遍历数组处理数据，并且返回新的数组

~~~html
<script>
    const arr = ['red', 'blue', 'green']
    const newArr = arr.map(function (ele, index) {
      console.log(ele) // 数组元素
      console.log(index) // 数组索引
      return ele + '颜色'
    })
    console.log(newArr)

</script>

// 输出
red
0
blue
1
green
2

red颜色
blue颜色
green颜色
~~~



## 数组中join方法

join可以把数组中所有元素转换成一个字符串

~~~html
const arr = ['red','blue','green']

// arr.join(' ') 里面是什么，字符串就以什么形式相连
console.log(arr.join('+'))

// 输出
red+blue+green
~~~









# Web APIs

作用：使用JS去操作html和浏览器

分类：DOM（文档对象类型）、DOM（浏览器对象模型）



## 获取DOM对象

**在html里面叫标签，在js里面叫DOM对象**

通过css选择器来获取，返回一个htmlelement对象

~~~html
document.querySelector('.box') //选中第一个

document.querySelectorALL('.box') //选中所有
~~~

~~~html
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>

  <style>
    .box {
      width: 500px;
      height: 500px;
    }
  </style>

</head>

<body>
  <div class="box">123</div>
  <div class="box">abc</div>

  <script>
    // 获取匹配到的第一个标签,两种方式都可以
    // const tmp = document.querySelector('div')
    const tmp = document.querySelector('.box')
    console.log(tmp)

  </script>
</body>

</html>
~~~



### 各种修改

**都是对象.属性=值**



#### 修改标签属性

##### 用style修改

对象.style.样式属性=值

在获取所有元素后使用数组遍历来改变属性

~~~html
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>

  <style>
    .box {
      background-color: red;
    }
  </style>

</head>

<body>

  <ul class="box">
    <li>测试1</li>
    <li>测试2</li>
    <li>测试3</li>
  </ul>

  <script>
    const lis = document.querySelectorAll('ul')
    console.log(lis);
    for (let k = 0; k < lis.length; k++) {
      lis[k].style.backgroundColor = 'green'
    }
  </script>
</body>

</html>
~~~



##### 用类名修改

适用于比较多的属性修改，以新替旧

~~~html
    <style>
        div {
            width: 200px;
            height: 200px;
            background-color: green;
        }

        .box {
            width: 300px;
            height: 300px;
            background-color: greenyellow;
        }
    </style>

    <div></div>
    <script>
        // 获取标签
        const tmp = document.querySelector('div')

        // 注意已经表明是类修改，因此是‘box’而不是‘.box’   
        tmp.className = 'box'
    </script>
~~~



##### 用classList修改

**重点**，可以追加、替换、删除类属性

~~~html
//追加类属性
tmp.classList.add('类名')

//删除类属性
tmp.classList.remove('类名')

//切换类属性
tmp.classList.toggle('类名')
~~~



#### 改文本

此方法不能获取表单的内容（innerHTML）

~~~html
<body>
    <div class="box">文本标签</div>
    <script>
        const tmp = document.querySelector('.box')

        //这个只显示已写文本
        tmp.innerText = '<strong>我不是标签</strong'
        
        //这个会显示加粗后的文本
        tmp.innerHTML = '<strong>我不是标签</strong'
    </script>
</body>
~~~



#### 改图片

~~~html
<body>
    <img src="./images/1.webp" alt="">
    <script>
        const img = document.querySelector('img')
        img.src = "./images/2.webp"
    </script>
</body>
~~~



#### 改表单

获取表单内容只能使用 `tmp.value`

~~~html
<input type="text" value="我是文本">
    <script>
        const tmp = document.querySelector('input')

        //修改文本内容
        tmp.value = '我不是文本'

        //让文本不显示
        tmp.type = 'password'
</script>
~~~



### 自定义属性

- 自定义标签一律以`data-xxx`开头
- 使用上一律以`tmp.dataset.xxx`对象方式获取

~~~html
<div data-id='1' data-spm='one'>1</div>

    <script>
        const tmp = document.querySelector('div')
        // 输出1
        console.log(tmp.dataset.id)

        // 输出one
        console.log(tmp.dataset.spm)
</script>
~~~



### 定时器

#### 间歇定时器

`let n = setInterval(被执行函数，1000)`，**一秒钟执行一次函数**

`clearInterval(n)`,关闭定时器



演示同意用户协议倒计时

~~~html
<!-- 先禁用按钮 -->
    <button disabled>我已同意用户协议(5)</button>

    <script>
        // 获取元素
        const tmp = document.querySelector('button')
        let i = 5

        // 设置倒计时,每秒修改一次文本
        let n = setInterval(function () {
            i--
            tmp.innerHTML = `我已同意用户协议(${i})`

            // 倒计时结束停止倒计时并激活按钮
            if (i === 0) {
                clearInterval(n)
                tmp.disabled = false

                tmp.innerHTML = '同意'
            }
        }, 1000);
</script>
~~~



#### 延迟定时器

`setTimeout(被执行函数，1000)`，延迟一秒执行函数

**只执行一次**





### 事件类型

#### 事件监听、绑定

由触发调用一个函数做出响应

`tmp.addEventListener('事件类型'，被执行函数)`，触发一次函数执行一次



演示点击按钮弹出对话框：

~~~html
<button>点击</button>
    <script>
        const tmp = document.querySelector('button')

        // ‘click’表示鼠标点击事件
        tmp.addEventListener('click', function () { alert('你好') })
</script>
~~~



#### 鼠标事件

`click`鼠标点击，`mouseenter`鼠标经过，`mouseleave`鼠标离开

#### 焦点事件

`focus`获取焦点，`blur`失去焦点

一般作用与表单的使用

~~~html
input.addEventListener('focus',functin(){})
~~~

#### 键盘事件

`Keydown`键盘按下触发 ，`Keyup`键盘抬起触发

#### 输入触发事件

得到用户输入内容案例：

~~~html
input.addEventListener('input',funtion(){console.log(input.value)})
~~~



#### 其他事件



##### 页面加载事件

- 加载外部资源（如图片、外联CSS和JS等）加载完毕时触发的事件

- 事件名`load`

	

1. **等待页面所有资源加载完毕才执行函数**

	~~~html
	window.addEventListener('load',function(){})
	~~~

   2. **等待图片资源加载完毕再执行函数**

	~~~html
	img.addEventListener('load',function(){})
	~~~





##### 页面滚动事件

**页面发生滚动时触发事件**

发生滚动一像素就发出一次提示

- 事件名`scroll`

~~~html
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>

  <style>
    body {
      height: 3000px;
    }
  </style>
</head>

<body>
  <script>
    window.addEventListener('scroll', function () {
      console.log('我滚了');

    })
  </script>
</body>
~~~



###### 获取元素被覆盖大小

`scrollLeft`:页面左边被覆盖的大小

`scrollTOP`：页面顶部被覆盖的大小

可以获取页面被覆盖的距离

**重点写法，单独记忆**

~~~html
// 获取整个页面被覆盖的量
      const n = document.documentElement.scrollTop

//如果被覆盖的像素大于十就消失
      if (n >= 10) {
        div.style.display = 'none'
      } else {
        div.style.display = 'block'
      }
~~~



###### 获取元素尺寸和位置

- **获取元素宽高**

	获取元素自身的宽和高（包括边框线等）

​		`offsetWidth`、`offsetHeight`

- **获取元素位置**

	相对于元素自己定位父级元素的左、上距离。**位置精确，不用自己查找**

	`offsetLeft`、`offsetTop`：是一个数字，不可更改

	**一般使用方法为当页面被卷曲的大小`scrollTOP`等于元素位置`offsetLeft`时，发生事件**





页面滚动使文字消失案例：

~~~html
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>

  <style>
    body {
      height: 3000px;
    }

    div {
      height: 200px;
      width: 200px;
    }
  </style>


</head>

<body>
  <div>
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
    这里有很多文字
  </div>

  <script>
    //绑定标签
    const div = document.querySelector('div')

    const tmp = document.addEventListener('scroll', function () {

      // 获取整个页面被覆盖的量
      const n = document.documentElement.scrollTop

      // 页面滚动超过十个像素，div标签就消失
      if (n >= 10) {
        div.style.display = 'none'
      } else {
        div.style.display = 'block'
      }
    })


  </script>
</body>
~~~



###### 电梯写法

~~~html
tmp.addEventListener('click',function(){
	window.scrollTo(0,0)
})
~~~





##### 页面尺寸事件

- 事件名：`resize`

**窗口尺寸发生变化时触发事件**

~~~html
window.addEventListener('resize',function(){
	console.log('窗口大小发生了变化')
})
~~~



获取盒子的宽和高案例：

`clientWidth`、`clientHeight`:获取盒子宽和高（不包含边框、线等）

~~~html
<script>
	const div=document.querySelector('div')
	console.log(div.clientWidth)
</script>
~~~





### 各种对象

#### 事件对象

`tmp.addEventListener('click',function(e){})`

`e`就是事件对象

`e.target`**是我们现在点击的那个对象**



**常用属性：**

- `type`获取当前事件类型
- `clientX`、`clientY`获取鼠标坐标
- `offsetX`、`offsetY`获取相对于当前DOM对象左上角的坐标
- `key`获取用户按下键盘键的值

~~~html
tmp.addEventListener('Keyup',function(e){})

if(e.key==='Enter')
{
	console.log('我按下了回车键')
}
~~~



#### 时间对象

获得时间：

~~~html
// 获得当前时间
const data=new Data()

// 获得指定时间
const data=new Data('2024-2-26 09:52:52')
~~~



| 日期对象的方法（date.getDate） | 备注           |
| ------------------------------ | -------------- |
| getFullYear()                  | 获取年         |
| getMonth()                     | 获取月         |
| getDate()                      | 获取一月所有天 |
| getDay                         | 获取星期       |
| getHours()                     | 获取消失       |
| getMinutes()                   | 获取分钟       |
| getSeconds()                   | 获取秒         |



**时间戳：**

时间戳是一个毫秒数，每个时间都有一个唯一对应的时间戳

| 获取方式   | 备注                                     |
| ---------- | ---------------------------------------- |
| getTime()  | console.log(date.getTime())              |
| new Date() | console.log(+new Date())                 |
| Date.now() | console.log(Date.now())   只能得到当前的 |





### 事件流

#### 事件捕获和事件冒泡

- 事件捕获是由父到子
- 事件冒泡是由子到父

~~~html
tmp.addEventListener('',function(){},true)
//第三个参数默认为false,就是事件冒泡
~~~



#### 阻止事件流/阻止默认行为

1. 只能由事件对象来阻止冒泡和捕获

~~~html
tmp.addEventListener('',function(e){},true)
e.stopPropagation() // 阻止事件流
~~~



2. 只能由事件对象来组织默认行为（如链接跳转等）

~~~html
<body>
  <form action="https://www.baidu.com">
    <input type="submit" value="免费注册">
  </form>

  <script>
    const tmp = document.querySelector('form')
    tmp.addEventListener('submit', function (e) {
      // 阻止提交
      e.preventDefault()
    })
  </script>
</body>
~~~





#### 事件委托

给父元素添加事件，所有子元素的事件都会冒泡到父元素身上，提高程序性能

~~~html
<body>
  <ul>
    <li>1</li>
    <li>2</li>
    <li>3</li>
    <li>4</li>
    <li>5</li>
  </ul>
  <script>
    const tmp = document.querySelector('ul')
    tmp.addEventListener('click', function (e) {

      // e.target表示现在点击的对象，点击变色
      e.target.style.color = 'red'
    })
  </script>
</body>
~~~



### 节点操作

**即增删查改**

#### 查

DOM树里面的每一个内容都是一个节点

~~~html
// 获取父节点
tmp.parentNode

// 获取子节点(只获取元素节点)，是一个子元素的数组
tmp.children

//获取下一个兄弟节点
tmp.nextElementSibling

//获取上一个兄弟节点
previousElementSibling
~~~



#### 增

- 追加节点。插入到父元素的最后一个子元素

	`父元素.appendChild(插入元素)`

	~~~html
	<body>
	  <ul></ul>
	  <script>
	    const ul = document.querySelector('ul')
	
	    // 创建新的html元素
	    const li = document.createElement('li')
	
	    ul.appendChild(li)
	  </script>
	</body>
	~~~

	

- 追加节点。插入到父元素的某个子元素之前

	`父元素。insertBefore(要插入的元素，在哪个元素前面)`

	~~~html
	<body>
	  <ul>
	    <li>1</li>
	    <li>2</li>
	    <li>3</li>
	  </ul>
	  <script>
	    const ul = document.querySelector('ul')
	
	    // 创建新的html元素
	    const li = document.createElement('li')
	
	    // ul.children是一个数组，包含了ul的所有子元素
	    ul.insertBefore(li, ul.children[0])
	  </script>
	</body>
	~~~



- 克隆节点。克隆一个现有节点,添加节点方式如上

	 `元素.cloneNode(bool)`

	true:本身+后代一起克隆

	false:只克隆本身

	~~~html
	<body>
	  <ul>
	    <li>1</li>
	    <li>2</li>
	    <li>3</li>
	  </ul>
	  <script>
	    const ul = document.querySelector('ul')
	
	    // 克隆了第一个li
	    const li1 = ul.children[0].cloneNode()
	    ul.appendChild(li1)
	  </script>
	</body>
	~~~



#### 删

- 只能通过父节点来删子节点

	`父元素.removeChild(要删除的子元素)`







## 获取BOM对象

BOM对象：浏览器模型

### Window对象

~~~mermaid
graph 
window-->navigator
window-->location
window-->document
window-->history
window-->screen
~~~

#### location对象

location的数据类型是对象，拆分保存了URL地址的各个组成部份

**常使用方法：**

- href属性，自动跳转

- ~~~html
	location.href='http://www.baidu.com'
	~~~

	

#### navigator对象

navigator的数据类型是对象，该对象记录了浏览器自身的相关信息

**常使用方法：**

- 通过userAgent检测浏览器的版本及平台，实现pc端移动端自动跳转

- ~~~html
	//检测userAgent（浏览器信息）
	!(function (){
		const userAgent = navigator.userAgent
		// 验证是否为AndroidsiPhone
		const android = userAgent.match(/(Android);?[\s\/]+([\d.]+)?/)
		const iphone = userAgent.match(/(1Phone\soS)\s(L\d ]+)/)
		/如果是Android iphone，则跳转至移动站点
		if (android || iphone) {
		location.href = 'http://itcast.cn' // 自己的站点网站
	}
	})()
	~~~

	

#### history对象

实现网页的前进后退

| history对象方法 | 作用                  |
| --------------- | --------------------- |
| back()          | 后退                  |
| forword()       | 前进功能              |
| go(参数)        | 参数1前进，参数-1后退 |

~~~html
history.back()
~~~





### 本地存储

放在浏览器里的小型数据库，刷新也不会消失



#### localStorage

- 永久性存在本地，关闭页面也不会消失，除非手动消除

- 可以多页面共享
- 以键值对的形式存储



**语法：**

~~~html
// 增
localStorage.setltem(key,value)

// 删,全部删除
localStorage.clear

// 删
localStorage.removeItem(key,value)

// 查
localStorage.getltem(key,value)
~~~



**实例：**

~~~html
localStorage.setltem('uname','AAA')
console.log(localStorage.getItem('uname'))
~~~



#### sessionStorage

- 生命周期为关闭浏览器窗口
- 只在同一个页面下数据共享
- 其他同localStorage





#### 存储复杂数据类型

- 需要以对象方式存储

- 需要将复杂数据类型转换成JSON字符串，再存储到本地

	

- **语法：JSON.stringify(复杂数据类型)**，先将对象转换成字符串

~~~html
const obj = {
	uname:'张三',
	age:18,
	gender:'男'
}

// 先转换成JSON字符串再存储
localStorage.setItem('jian',JSON.stringify(obj))

// 打印得到{“uname”：“张三”，“age”：“18”，“gender”：“男”} 字符串
console.log(localStorage.getItem('jian'))
~~~



- **语法：**JSON.parse(转换后的字符串)，再将字符串转换成对象

~~~html
console.log(JSON.parse(localStorage.getItem('jian')))
~~~


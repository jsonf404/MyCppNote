# Node.js简介

- Node.js是js的一个运行环境
	- 浏览器是js前端开发环境
	- Node.js是js后端开发环境
	- Node.js里面无法调用DOM和BOM等浏览器内置API
	- 在vscode终端输入node xxx.js即可运行



- nodemon工具

	- 可以时刻监听代码变化，自动重启项目，不用手动重启

	- ~~~js
		npm install -g nodemon
		~~~

	- 再次启动程序在终端输入：

		~~~js
		nodemon xxx.js
		~~~

		

​		

# fs文件系统模块

- 操作文件的模块
- 导入方式：`const tmp = require('fs')`



## 读文件

```html
tmp.readFile(参数1，参数2，function({}))
```

- 参数1：必选参数，字符串，表示文件路径
- 参数2：可选参数，表示读文件的编码格式
- 参数3：必选参数，回调函数拿到读取到的结果



- 读取成功->err的值为null

- 读取失败->err的值为错误对象，data的值为undefined

	~~~js
	const tmp = require('fs')
	tmp.readFile('./files/1.txt', 'utf8', function (err, data) {
	  // 打印失败结果
	  console.log(err)
	
	  // 打印成功结果
	  console.log(data)
	})
	~~~

	

## 写文件

**是以先清空再写入的方式**

~~~html
tmp.writeFile(参数1，参数2，参数3，参数4)
~~~

- 参数1：必选参数，字符串，文件存储路径
- 参数2：必选参数，字符串，写入内容
- 参数3：可选参数，表示写入文件的格式
- 参数4：必选参数，文件写完之后的回调函数



- 写入成功->err值为null

- 写入失败->err值为错误对象

	~~~js
	const tmp = require('fs')
	
	tmp.writeFile('./files/1.txt', 'aaaaaaaa', function (err) {
	  console.log(err);
	})
	~~~

	

## 路径动态拼接

- 使用`__dirname`,其表示当前文件所在目录

	~~~html
	tmp.readFile(__dirname+'files/1.txt','utf8',function (err, data))
	~~~

	

# path路径模块

- 导入方式：`const tmp =require('path')`



## 路径拼接

~~~js
tmp.join(路径片段的序列)
~~~



- `’../‘`会抵消一层路径

	~~~js
	const tmp = tmp.join('/a','/b/c','../','./d','e')
	
	// 输出\a\b\d\e
	console.log(tmp)
	~~~



- **与__dirname搭配使用**

	~~~js
	const tmp = tmp.join(__dirname,'./files/1.txt')
	
	// 输出当前文件所在目录\files\1.txt
	console.log(tmp)
	~~~

	

## 获取路径中文件名

~~~js
tmp.basename(参数1，参数2)
~~~

- 参数1：必选参数，表示文件路径的字符串

- 参数2：可选参数，表示文件扩展名**（加入此参数会把文件扩展名删除）**

- 返回值为路径中的最后一部分，通常是文件名

	

	~~~js
	const tmp = require('path')
	
	// 会输出1
	console.log(tmp.basename('./files/1.txt', '.txt'))
	~~~



## 获取路径中文件扩展名

~~~js
tmp.extname(参数1)
~~~

- 参数1：必选参数，表示文件路径的字符串
- 返回值：表示扩展名的字符串





# http

- **使用http.createServer()方法，可以把一台普通电脑变成一台Web服务器**

- 导入方法：`const tmp = require('http')`



## 相关概念

- IP地址：互联网上每台计算机的唯一标识
	- 一般使用a.b.c.d的形式来表示，abcd都是0~255之间的十进制整数



- 域名和域服务器
	- 域名与IP一一对应，就是网站名



- 端口号
	- 一台电脑上可以运行很多个web服务，**每个web服务都对应一个唯一的端口号**，客户发出的请求通过端口号可以被精确的交给对应的web服务进行处理



## 创建web服务器

- 导入http模块

	~~~js
	const tmp = require('http')
	~~~

	

- 创建web服务器实例

	~~~js
	const server = tmp.createServer()
	~~~

	

- 为服务器绑定request事件，监听客户需求

	~~~js
	server.on('request',(req,res) => {
	    console.log('Someone visit our web server.')
	})
	~~~



- 调用服务器实例的.listen()方法，启动服务器

	~~~js
	// 80是端口号
	server.listen(80,() => {
	    console.log('http server running at http://127.0.0.1')
	})
	~~~



~~~js
const tmp = require('http')

const server = tmp.createServer()

server.on('request', (req, res) => {
  console.log('Someone visit our web server.')
})

// 80是端口号
server.listen(80, () => {
  console.log('http server running at http://127.0.0.1')
})
~~~



### req请求对象

req是请求对象，包含了与客户端相关的数据和属性

| 数据       | 备注                   |
| ---------- | ---------------------- |
| req.url    | 客户端请求的URL地址    |
| req.method | 客户端请求的method类型 |



- 案例输出为：**你请求的URL是/,请求方式是GET**

~~~js
const tmp = require('http')

const server = tmp.createServer()

server.on('request', (req) => {
  console.log('Someone visit our web server.')

  const url = req.url
  const method = req.method

  console.log(`你请求的URL是${url},请求方式是${method}`);

})

// 80是端口号
server.listen(80, () => {
  console.log('http server running at http://127.0.0.1')
})
~~~



### res响应对象

- 在处理服务器的requst事件时，拿到一些相应结果内容打印到客户端，并终止请求

- 方法：`res.end()`

~~~js
const tmp = require('http')

const server = tmp.createServer()

server.on('request', (req, res) => {
  console.log('Someone visit our web server.')

  const url = req.url
  const method = req.method

  const str = `你请求的URL是${url},请求方式是${method}`
  console.log(str);

  // 调用res.end()方法，向客户响应一些内容
  res.end(str)
})

// 80是端口号
server.listen(80, () => {
  console.log('http server running at http://127.0.0.1')
})
~~~



### 解决中文乱码

在res响应对象返回信息到浏览器时，会出现中文乱码情况，设置响应头

~~~js
const str = `你请求的URL是${url},请求方式是${method}`
res.setHeader('Content-Type', 'text/html;charset=utf-8')
res.end(str)
~~~





## 根据不同的url响应不同的html内容

- 样例入下

	~~~js
	const tmp = require('http')
	
	const server = tmp.createServer()
	
	server.on('request', (req, res) => {
	  const url = req.url
	  let content = '<h1>404 Not found!</h1>'
	  if (url === '/' || url === '/index.html') {
	    content = '<h1>首页</h1>'
	  } else if (url === '/about.html') {
	    content = '<h1>关于页面</h1>'
	  }
	
	  res.setHeader('Content-Type', 'text/html;charset=utf-8')
	  res.end(content)
	})
	
	// 80是端口号
	server.listen(80, () => {
	  console.log('http server running at http://127.0.0.1')
	})
	~~~

	

# 模块化

## 加载模块方法

- 内置模块：fs、path、http等
- 自定义模块：用户创建的每个.js文件
- 第三方模块，要自己先下载

~~~js
const tmp = require('fs')

const tmp = require('./custom.js')

const tmp = require('moment')
~~~





## 向外共享模块作用域中的成员

- 模块作用域：自定义模块中定义的变量、方法等成员，**只能在当前模块内被访问**，防止变量污染

	

- 由于每个.js对象模块中都有一个module对象，储存了和当前模块有关的信息



- **所以可以使用`module.exports`对象将模块内的成员共享出去，外界在使用`require()`方法导入自定义模块时，得到的就是module.exports所指向的对象**



- 需要两个文件

	1. module.exports文件，共享属性

		**module.exports和exports效果相同，但是module.exports属性覆盖exports属性**

		~~~js
		// 向module.exports对象上挂载一个username属性
		exports.username = '张三'
		
		// 向module.exports对象上挂载一个sayHello方法
		exports.sayHello = function () {
		  console.log('Hello!');
		
		}
		
		const a = 10
		exports.age = a
		~~~

		

	2. require文件，接收属性

		~~~js
		// 在外界（如本界）导入一个自定义模块时，得到的成员，就是自定义模块中module.exports指向的那个对象
		const tmp = require('./1.js')
		
		console.log(tmp);
		~~~

		

	3. 输出

		~~~js
		{ username: '张三', sayHello: [Function (anonymous)], age: 10 }
		~~~






# npm与包

## 相关信息

- 第三方模块也叫包，npm就是下包的工具
- 包共享平台：[搜索需要的包,查看使用文档](https://www.npmjs.com/)



- 项目中`node_modules`文件夹用来存储已安装到目录中的包

- 项目中`package.json`用来记录下载了哪些包，根据这个文件来下载需要的包

	

- 项目中`package-lock.json`配置文件用来记录`node_modules`目录下每一个包的相关信息





## 使用举例

- 使用npm实现格式化时间例子
	- 使用npm下载包，在项目中安装格式化时间的包moment
	- 使用require()导入格式化时间的包
	- 参考moment的官方API文档对时间进行格式化



- **安装包的命令：**

	~~~js
	// 项目终端输入指令
	npm i 包的完整名称
	~~~

- 卸载包的命令：

	~~~js
	npm uninstall 包的完整名称
	~~~

	

- 使用案例

	~~~js
	// 导入需要的包,一般使用常量名来命名包
	const moment = require('moment')
	
	const time = moment().format('YYY-MM-DD HH:mm:ss')
	console.log(time);
	~~~







## 包管理配置文件（package.json）

- 作用：package.json配置文件，用来**记录安装了哪些包**

- 创建命令：

	~~~
	// 快速创建package.json文件
	npm init -y
	~~~



- dependencies节点
	- `package.json`文件中，有一个dependencies节点，专门用来记录使用`npm install`命令安装了哪些包



- devDependencies节点

	- 某些包只在开发过程中需要使用，上线后不需要，建议将其放到devDependencies节点中

	- 安装命令：

		~~~js
		npm i 包名 -D
		~~~

		



## 多人协作问题

- 在实际开发过程中，多人协作时需要使用到GitHub，而项目源文件体积很小，内存大部分被包占用，**因此上传源码时可以剔除`node_modules`文件再上传**
- 因此可以**在项目根目录里面创建一个叫`package.json`的配置文件，用来记录安装了哪些包**，共享成员根据其下载所需要的包即可

- 在上传文件到GitHub时，把`node_modules`文件夹**添加到.gitignore忽略文件中**

	

- 一次性下载所有需要的包:

	- ~~~html
		// 执行此命令会直接读取package.json里面的节点信息，下载所有包
		npm i
		~~~

		

## 包的分类

- `i5ting_toc`

	- 作用：一个可以把md文档转换成html页面的小工具

	- 使用教程：

		~~~js
		// 先安装成全局包
		npm install -g i5ting_toc
		
		// 调用包
		i5ting_toc -f 要转换的md文件路径 -o
		~~~

		



# express

## 基本概念

- npm的第三方包，**express是基于http封装起来的**，都是专门用来创建Web服务器的

- 安装方式

	~~~js
	npm i express@4.17.1
	~~~



- 创建基本的Web服务器

	~~~js
	// 导入express
	const express = require('express')
	
	// 创建web服务器
	const app = express()
	
	// 调用app.listen（端口号，启动成功后的回调函数），启动服务器
	app.listen(80, () => {
	  console.log('xxxxx')
	})
	~~~





## 监听GET/POST请求

- 使用`app.get()`/`app.post()`方法

- 语法格式如下：

	~~~js
	app.get('参数1'，function(req,res){
	    // 处理函数
	})
	~~~

	- 参数1：客户端请求的URL地址
	- req：请求对象（包含相对应的属性和方法）
	- res：响应对象（包含相对应的属性和方法）



### 把内容响应发送给客户端

- 使用`res.send()`方法

- 语法格式如下：

	~~~js
	app.get('/user', (req, res) => {
	  // 向客户发送json对象
	  res.send({ name: '张三'，age: '20', gender: '男' })
	})
	
	app.post('/user', (req, res) => {
	  // 向客户端发送文本
	  res.send('请求成果')
	})
	~~~



### 获取URL中携带的查询参数

- 使用`req.query`对象，可以访问到客户端通过查询字符串的形式，发送到服务器的参数

- 语法格式：

	~~~js
	app.get('/',(req,res)=>{
	  console.log(req.query)  
	})
	~~~

	

### 获取URL中携带的动态参数

- 使用`req.params`对象，可以访问到URL中，通过：匹配到的动态参数

- 语法格式

	~~~js
	app.get('/user/:id/:name',(req,res) => {
		console.log(req.params)
	})
	
	// 输入http://127.0.0.1/user/1/zs
	// 输出 id:1
	//	   name:zs
	~~~





## 托管静态资源

- 方法：`express.static()`

- 通过这个方法，可以便利的创建一个静态资源服务器

- 可以通过下述代码将public目录下的图片、css文件、js文件对外开放

	~~~js
	app.use(express.static('public'))
	~~~

	- 由此代码，就可以访问public目录下的所有文件



- 托管多个静态资源目录：多次调用`express.static()`即可



## 路由

### 路由简介

- 路由就是一种映射关系
- 在express 中，路由就是客户端的请求和服务器处理函数之间的关系



- 路由由三部分组成

	- 格式如下：

		~~~js
		app.参数(参数2,参数3)
		~~~

	- 参数1：请求类型
	- 参数2：请求的URL地址
	- 参数3：处理函数



- 案例如下：

	~~~js
	// 匹配GET请求，且请求URL为/
	app.get('/', function (req, res) {
	  res.send('AAAA')
	})
	
	// 匹配POST请求，且请求URL为/
	app.post('/', function (req, res) {
	  res.send('BBB')
	}
	~~~

	



### 路由的模块化

- 路由不建议直接挂载到app上，而是将其抽离为单独的模块

	- 创建路由对应的.js文件

	- 调用`express.Router()`函数创建路由对象

	- 向路由对象上挂载具体的路由

	- 使用`module.exports`向外共享路由对象

	- 使用`app.use()`函数注册路由模块

		

- **创建路由模块案例**

	- 单独.js文件存放路由模块，其他文件在require这个文件时可以直接得到路由对象

	- ~~~js
		// 创建路由模块，导入express
		const express = require('exoress')
		
		// 创建路由对象
		const router = express.Router()
		
		// 挂载具体的路由
		router.get('/user/list', (req, res) => {
		  res.send('Get user list')
		})
		
		router.post('/user/list', (req, res) => {
		  res.send('Add new user')
		})
		
		// 向外导出路由对象
		~~~



- **注册路由模块案例**

	- 在其他需要使用到路由模块的地方

	- ~~~js
		const express = require('express')
		const app = express()
		
		// 导入路由模块
		const router = require('./1.js')
		
		//注册路由模块
		app.use(router)
		
		app.listen(80, () => {
		  console.log('创建成功')
		})
		~~~

		

## express中间件

- 定义中间件函数

	- ~~~js
		const mw = function(req,res,next){
		    console.log('这是一个中间件函数')
		    // 调用中间件函数，转交流转关系
		    next()
		}
		~~~





## 使用express写接口

### 前置代码

- 创建服务器

- 创建API路由模块（路由的模块化知识）

	- ~~~js
		// 导入express
		const express = require('express')
		
		// 创建服务器实例
		const app = express()
		
		
		// 导入路由模块
		const router = require('./1-1')
		
		// 把路由模块注册到全局中间件上,添加统一前缀'/api'
		app.use('/api', router)
		
		
		
		//启动服务器
		app.listen(80, () => {
		  console.log('启动成功')
		})
		~~~

	- ~~~js
		const express = require('express')
		
		const router = express.Router()
		
		
		module.exports = router
		~~~



### 编写GET接口

- 先获取客户端通过查询字符串发给服务器的数据，再通过`req.send()`方法把数据反馈给客户端

	- ~~~js
		const express = require('express')
		
		const router = express.Router()
		
		// 挂载对应的路由,指定的url前缀
		router.get('/get', (req, res) => {
		  // 获取客户端发过来的数据
		  const query = req.query
		
		  // 响应结果
		  res.send({
		    status: 0, //0失败1成功
		    msg: 'GET 请求成功', // 状态描述
		    data: query + "aaaa" // 返回给客户端的数据
		  })
		})
		
		module.exports = router
		~~~

	

### 编写POST接口

- req.query方法改为req.body即可，其余不变

- **使用`req.body`需要添加一个中间件到另一个主文件**

	- ~~~js
		app.use(express.urlencoded({extended:false}))
		~~~

	

	

	- ~~~js
		// 挂载对应的路由,指定的url前缀
		router.get('/post', (req, res) => {
		  // 获取客户端发过来的数据
		  const body = req.body
		
		  // 响应结果
		  res.send({
		    status: 0, //0失败1成功
		    msg: 'GET 请求成功', // 状态描述
		    data: query + "aaaa" // 返回给客户端的数据
		  })
		})
		~~~



### 接口跨域问题

- 安装cors中间件解决跨域问题

	- 安装中间件

		~~~js
		npm install cors
		~~~

	- 导入中间件

		~~~js
		const cors = require('cors')
		~~~

	- 在路由之前调用`app.use(cors())`来配置中间件





# MySQL

## 安装和配置MySQL

- MySQL Server:专门提供数据存储和服务的软件
- MySQL Workbench:可视化MySQL管理工具，方便操作存储在数据库里面的数据



- DataType数据类型：
	- int 整数
	- varchar(45)  字符串
	- tinyint(1)  布尔值



- 字段的特殊标识
	- PK  主键，唯一标识
	- NN  值不允许为空
	- UQ  值唯一
	- AI 值自动增加



## SQL基本语句

| 方法                    | 代码                                                         |
| ----------------------- | ------------------------------------------------------------ |
| 查询所有列，*表示所有列 | select * from 表名                                           |
| 查询指定列              | select 列名称，列名称  from 表名称                           |
|                         |                                                              |
| 插入新的行              | insert into 表名 （列1，列2） values（值1，值2）             |
|                         |                                                              |
| 更新                    | updata 表名 set 列名 = 新值 where 列名 = 某值                |
|                         |                                                              |
| 删除                    | delete from 表名 where 列名 = 值                             |
|                         |                                                              |
| 排序                    | select * from users order by status //升序<br>select * from users order by status desc //降序 |
|                         |                                                              |
| 返回查询到的总条目数    | select count( * ) from users where status = 0<br>返回值示例：count( * ) 4 |
|                         |                                                              |
| as关键字设置别名        | select count( * ) from users where status = 0<br>返回值示例：total 4 |





## express导入mysql

### 配置

- 下包

	~~~js
	npm install mysql2
	~~~

	

- 导入驱动

	~~~js
	// 导入mysql模块
	const mysql = require('mysql2')
	
	// 建立于数据库的连接
	const db = mysql.createPool({
	    host:'127.0.0.1',		// 数据库的ip地址
	    user:'root',			// 登录数据库的账号
	    password:'admin123',	// 登录数据库的密码
	    database:'mydb'			// 指定要操作哪个数据库
	})
	~~~

	

- 测试运行状态，调用db.query()函数即可

	~~~js
	db.query('SELECT 1',(err,result) => {	// err错误对象，result结果对象
	    if(err)
	        return colose.log(err.message)
	    	// 只要能打印出[RowDataPacket{'1':1}]的结果，就可以证明数据库连接正常
	    console.log(result)
	})
	~~~




- 运行

  ~~~js
  nodemon Node.js
  ~~~

  



### 增删查改语句

- 查（**user是表名**）

  ~~~js
  db.query('select * from user', (err, results) => {
      // user是表名
    if (err)
      return console.log(err.message);
    console.log(results);
  
  })
  ~~~



- 插入（占位符插入）

  ~~~js
  // 要插入的数据
  const cha = { username: 'ww', password: '12345', status: 0 }
  
  const sqlStr = 'insert into user (username,password,status) values(?,?,?)'
  
  db.query(sqlStr, [cha.username, cha.password, cha.status], (err, results) => {
    if (err)
      return console.log(err.message)
  
  
    // 报错提示方法，如果行的影响数为1，即发生了更改，就提示插入成功
    if (results.affectedRows === 1) {
      console.log('数据插入成功');
    }
  })
  ~~~



- **便捷插入**（数据较多，且数据对象每个属性都和数据表字段一一对应）

  占位符有几个，中括号里面就有几个数据

  ~~~js
  // 要插入的数据
  const cha = { username: 'www', password: '123455', status: 1 }
  
  
  // 语句更改区域
  const sqlStr = 'insert into user set ?'
  // 语句更改区域
  db.query(sqlStr, [cha], (err, results) => {
    if (err)
      return console.log(err.message)
  
  
    // 报错提示方法，如果行的影响数为1，即发生了更改，就提示插入成功
    if (results.affectedRows === 1) {
      console.log('数据插入成功');
    }
  })
  ~~~

  

- 更新

  ~~~js
  // 指定要更新的数据对象
  const geng = { id: 1, username: 'AAA', password: '111' }
  
  const sqlStr = 'update user set username=?,password=? where id=?'
  
  db.query(sqlStr, [geng.username, geng.password, geng.id], (err, results) => {
    if (err)
      return console.log(err.message)
  
    if (results.affectedRows === 1)
      console.log('数据更新成功');
  
  })
  ~~~

  

- **便捷更新**（数据较多，且数据对象每个属性都和数据表字段一一对应）

  占位符有几个，中括号里面就有几个数据

  ~~~js
  // 指定要更新的数据对象
  const geng = { id: 1, username: 'BBB', password: '222' }
  
  // 语句更改区域
  const sqlStr = 'update user set ? where id=?'
  
  // 语句更改区域
  db.query(sqlStr, [geng, geng.id], (err, results) => {
    if (err)
      return console.log(err.message)
  
    if (results.affectedRows === 1)
      console.log('数据更新成功');
  })
  ~~~

  

- 删除（使用id为标识符）

  ~~~js
  const sqlStr = 'delete from user where id = ?'
  
  db.query(sqlStr, [1], (err, results) => {
    if (err)
      return console.log(err.message);
    if (results.affectedRows === 1)
      console.log('数据删除成功！');
  
  })
  ~~~

  

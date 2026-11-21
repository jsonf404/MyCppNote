

# HTML5&CSS3

字符实体

| 字符 | 实体名  |
| ---- | ------- |
|      | &nbsp+; |
| <    | &lt+;   |
| >    | &gt+;   |

## HTML

~~~mermaid
graph 
超文本标记语言-->超文本-->链接
超文本标记语言-->标记-->标签-->a(<>文本<>)
~~~

### html骨架

~~~html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
</body>
</html>
//！+enter直接生成
~~~

| html  | 整个网页                   |
| :---- | :------------------------- |
| head  | 网页头部，给浏览器看的内容 |
| body  | 网页主体，给用户看的内容   |
| title | 网页标题                   |



### 各种标签

相对路径：从当前文件夹出发  

绝对路径：从盘符出发

| 相对路径 | 备注                       |
| -------- | -------------------------- |
| .        | 表当前文件夹               |
| ..       | 表上一级文件夹，以此类推   |
| /        | 进入文件夹                 |
| ./       | 表示进入当前文件所在文件夹 |



| 文本标签                     | 备注                                    |
| ---------------------------- | --------------------------------------- |
| 标题标签                     | <h1>一级标题</h1><br>    h1->h6逐渐缩小 |
| 换行标签<br>  水平线标签<hr> | 都是单标签                              |

| 文本格式化标签 | 备注                  |
| -------------- | --------------------- |
| strong/b       | <strong>加粗</strong> |
| em/i           | <em>倾斜</em>         |
| ins/u          | <ins>下划线</ins>     |
| del/s          | <del>删除线</del>     |

| 图像标签（单标签）         | 备注                              |
| -------------------------- | --------------------------------- |
| &lt;img src="./图片的URL"> | 输入 ./  vscode自动提示URL        |
| &lt;img src="" alt="">     | 替换文本，图片不显示就显示alt文本 |
| &lt;img src="" title="">   | 鼠标悬停在图片上显示title文本     |

| 超链接标签（双标签）                                         | 备注                                              |
| ------------------------------------------------------------ | ------------------------------------------------- |
| &lt;a href="https://www.baidu.com/"&gt;跳转到百度&lt;/a&gt;  | 如代码所示，跳转到百度网页                        |
| &lt;a href="https://www.baidu.com/" target="_blank"&gt;跳转到百度&lt;/a&gt; | 加入target="_blank"，可以打开新网页同时保留现网页 |
| 跳转到本地文件用相对路径写法                                 |                                                   |

| 音频标签（双标签）                    | 备注                             |
| ------------------------------------- | -------------------------------- |
| &lt;audio src="">&lt;/audio>          | src：音频的URL,支持MP3、Ogg、Wav |
| &lt;audio src="" controls>&lt;/audio> | 显示音频控制面板                 |
| &lt;audio src="" loop>&lt;/audio>     | 循环播放                         |
| &lt;audio src="" autoplay>&lt;/audio> | 自动播放                         |



### 列表

#### 无序列表

~~~html
<ul>
<li>1</li>
<li>2</li>
<li>3</li>
</ul>
~~~

ul是无序列表，li是列表条目

ul里面只能包含li，li里面随便写

#### 有序列表

~~~html
<ol>
<li>1</li>
<li>2</li>
<li>3</li>
</ol>
~~~

其他同有序列表

#### 定义列表

~~~html
<dl>
    <dt>标题</dt>
    <dd>描述</dd>
    <dd>描述</dd>
</dl>
~~~

dl是定义列表，dt是标题，dd是详情



### 表格

#### 表格标签

| 标签名 | 备注       |
| ------ | ---------- |
| table  | 表格       |
| tr     | 行         |
| th     | 表头单元格 |
| td     | 内容单元格 |
| border | 加边框     |

~~~html
<table border="1">
    <tr>
        <th>语文</th>
        <th>数学</th>
        <th>英语</th>
    </tr>
    <tr>
        <td>100</td>
        <td>99</td>
        <td>99</td>
    </tr>
    <tr>
        <td>100</td>
        <td>99</td>
        <td>99</td>
    </tr>
</table>
~~~

#### 表格合并

~~~html
 <table border="1">
        <tr>
            <th>语文</th>
            <th>数学</th>
            <th>英语</th>
        </tr>
        <tr>
            <td>100</td>
            <td rowspan="2">99</td> <!-- 跨行合并，合并几个roespan就等于几 -->
            <td>99</td>
        </tr>
        <tr>
            <td>100</td>
            <!-- <td>99</td> 删除被合并的单元格 -->
            <td>99</td>
        </tr>
    </table>
~~~

```html
<table border="1">
    <tr>
        <th>语文</th>
        <th>数学</th>
        <th>英语</th>
    </tr>
    <tr>
        <td>100</td>
        <td>99</td>
        <td>99</td>
    </tr>
    <tr>
        <td colspan="3">100</td> <!--跨列合并，合并几个colspan就等于几 -->
        <!-- <td>99</td>
        <td>99</td> -->  <!--删除合并后的表格-->
    </tr>
</table>
```



### 表单

常用于收集用户信息（登录，注册，搜索区域）

#### input标签

input标签的type属性值不同，功能就不同

| type属性值                             | 备注                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| text                                   | 文本框，用于输入单行文本                                     |
| password                               | 密码框                                                       |
| radio                                  | 单选框                                                       |
| checkbox                               | 多选框                                                       |
| file                                   | 上传文件 <br/>&lt;input type="flie" multiple><br/><!-- 可以上传多个文件 --> |
| <input type="text" placeholder="文本"> | placeholder=“文本”，文本显示输入框内的提示语句               |

~~~html
	文本框：<input type="text" placeholder="请输入文本"><br><br>
    密码框：<input type="password"><br><br>
    单选框：<input type="radio"><br><br>
    多选框：<input type="checkbox"><br><br>
    上传文件：<input type="file">
~~~

#### 单选框

~~~html
 性别:
<input type="radio" name="a">男
<input type="radio" name="a" checked>女
<!-- name="文本"，name等于同一个文本即可实现单选效果，checked实现默认选择效果（同适用于多选框） -->
~~~

#### 下拉菜单

selet嵌套option,option是下拉菜单的每一项，selected默认选择

~~~html
选择：
<select>
    <option>1</option>
    <option>2</option>
    <option>3</option>
    <option selected>4</option>
</select>
~~~

#### 文本域标签  

适用于多行文本输入,自动换行

~~~html
<textarea>已有文字</textarea> 
~~~

#### lable标签

增大点击范围,两种方法，都可以实现点击男，女文字都可以选中单选框

~~~html
<input type="radio" name="a" id="man"> <label for="man">男</label>
<label><input type="radio" name="a">女</label>
~~~

#### 按钮标签

| type属性 | 备注                           |
| -------- | ------------------------------ |
| submit   | 提交数据到后台（默认功能）     |
| reset    | 重置按钮，重置输入数据         |
| button   | 默认无功能，配合js派生其他功能 |

~~~html
<form>
    用户名：<input type="text"><br><br>
    密  码：<input type="password"><br><br>
    <button type="reset">清空</button>
</form>
~~~

必须包裹在form内才能将按钮功能和文本绑定

#### 无语义布局标签

~~~html
<div>这是 div 标签</div> <!--独占一行，大盒子-->
<span>这是 span 标签</span> <!--不换行，小盒子-->
~~~





## CSS

作用：美化html

### 代码简写

| 结构名       | 简写法    | 效果                              |
| ------------ | --------- | --------------------------------- |
| 类选择器     | div.box   | <div class="box"></div>           |
| id选择器     | div#box   | <div id="box"></div>              |
| 同级标签     | div+p     | <div></div><p></p>                |
| 父子级标签   | div>p     | <div><p></p></div>                |
| 多个相同标签 | div*3     | <div></div><div></div><div></div> |
| 有内容标签   | div{文本} | <div>文本</div>                   |

~~~css
<!-- 生成如下代码 -->
    <style>
        div{
          width: 500px;
          height: 200px;
          background-color:black
        }
</style>

/* 输入w500+h200+bgc 即可 */
~~~



### 转换显示模式

~~~html
<style>
disply:block;
</style>
~~~

| 属性值       | 效果   |
| ------------ | ------ |
| block        | 块级   |
| inline-block | 行内块 |
| inline       | 行内   |



### 引入方式

| 引入方式   | 备注                                            |
| ---------- | ----------------------------------------------- |
| 内部样式表 | CSS代码写在.html文件的style标签里面             |
| 外部样式表 | CSS代码写在.css文件中，在HTML中使用link标签引入 |
| 行内样式   | 搭配js使用                                      |

#### 内部样式表

书写位置：<strong>在title标签下方添加style双标签，style标签里面写CSS代码</strong>，通过选择器找到对应的html标签然后美化它

通过h1找到“体验CSS”,把他变成红色：

~~~html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>

<style>
/* CSS 代码 ,由style包裹写在title下面*/
/* 选择器 {CSS 属性} */
h1{
    color:red;
}
</style>

</head>
<body>

<h1>体验CSS</h1>

</body>
</html>
~~~

#### 外部样式表

~~~html
<!-- 同样在title下加入link代码 -->
<link rel="stylesheet" href="./my.css">
~~~

~~~css
/* css代码直接写，不用包裹在style下面 */
h1{
    color: red;
}
~~~

#### 行内样式

~~~html
<!-- 行内样式，style="CSS属性即可" -->
<h1 style="color: green;font: 100;">体验CSS</h1>
~~~



### 文字控制属性

| 描述            | 备注                                |
| --------------- | ----------------------------------- |
| 文字大小        | font-size                           |
| 文字粗细        | font-weight                         |
| 文字倾斜        | font-style                          |
| 文字颜色        | color                               |
| 字体族（宋体…） | font-family                         |
| 字体复合属性    | 写法：font:italic 700 30px/2 楷体； |
| 文本缩进        | text-indent：2em(任意文本缩进2字符) |
| 文本对齐        | text-align：left/center/right       |
| 文本行高        | line-height                         |
| 修饰线          | text-decoration:none/underline      |



### 背景控制属性

| 描述           | 备注                                                         |
| -------------- | ------------------------------------------------------------ |
| 背景色         | background-color（bgc）                                      |
| 背景图         | background-image（bgi）                                      |
| 背景图平铺方式 | background-repeat（bgr）                                     |
| 背景图位置     | background-position（bgp）                                   |
| 背景图缩放     | background-size（bgs）<br />**cover：**图片完全覆盖背景<br />**contain：**图片完全装入背景 |
| 背景图固定     | background-attachment（bga）<br />**fixed：**固定背景图      |
| 背景复合属性   | background                                                   |

| 平铺属性  | 效果         | 位置属性 | 效果 |
| --------- | ------------ | -------- | ---- |
| no-repeat | 不平铺       | left     |      |
| repeat    | 平铺（默认） | right    |      |
| repeat-x  | 水平方向平铺 | center   |      |
| repeat-y  | 垂直方向平铺 | top      |      |
|           |              | bottom   |      |

~~~html
background-position: bottom left;
<!-- 图片到左下角 -->

background-position: 50px center;
<!-- 右移50，上下居中 -->
~~~



### CSS选择器

查找标签，改变样式

#### 标签选择器

所有同名标签设置相同样式

#### 类选择器

差异化同名标签的显示效果,实现方法如下（哪里想改变就在哪里引用）

~~~html
<style>
    .red{
        color:red;
    }
    
    .size{
        font-size:50px;
    }
</style>

<!-- 使用类选择器 -->
<!-- 一个标签只能一个class,可以多个类名，空格隔开即可 -->
<div class="red size">这是 div 标签</div>
~~~

#### id选择器

同类选择器效果，一般搭配js使用，较少搭配CSS。一个id选择器在一个页面只使用一次

~~~html
<style>
    #red{
        color:red;
    }
</style>

<!-- 使用id选择器 -->
<div id="red">这是 div 标签</div>
~~~

#### 通配符选择器

查找所有标签，设置相同样式

~~~html
<style>
    *{
        color:red;
    }
</style>

<!-- 使用 通配符选择器 -->
<!-- 所有文本样式变成一样 -->
<div >这是 div 标签</div>
<div >这是 div 标签</div>
~~~



多个选择器组成

#### 后代/子代选择器

后代选择器会改变父辈的所有后代的属性，子代选择器只改变子代

~~~html
<!-- 后代选择器 -->
<style>
    div span{
        color:red;
}
</style>

<!-- 子代选择器 -->
<style>
    div > span{
        color:red;
}
</style>


<div>
    <span>这是 div 的儿子span </span>
    <p>
        <span>孙子 span</span>
    </p>
</div>
~~~

#### 并集选择器

~~~html
<style>
    div,
    p,
    span{
	color:red;
    }
</style>

<div>这是div标签</div>
<p>这是p标签</p>
<span>这是span标签</span>
~~~

#### 伪类选择器

伪类表示元素的某个状态，满足元素的某个状态才改变样式

鼠标悬停状态：标签名：hover

~~~html
<style>
    h1:hover{
        color:red;
    }
</style>

<h1>我要变红</h1>
~~~

#### 结构伪类选择器

改变多个同名标签其中的一个或多个

~~~html
 <style>
     /* 第三个标签样式变绿 */
    div:nth-child(3){
        color:red;
    }
</style>

<div>AAA</div>
<div>AAA</div>
<div>AAA</div>
~~~



### CSS特性

#### 继承性

子集默认继承父级的<strong>文字控制属性</strong>,不能改变标签默认样式

~~~html
<style>
    body{
        font-size:30px;
        color:red;
    }
</style>

<!-- body的子集默认接收所有文字控制书写 -->
<body>
    <div>div 标签</div>
</body>
~~~

#### 层叠性

同名标签相同属性后面覆盖前面的，不同的属性会叠加都生效

~~~html
<style>
    div{
        color:red;
        font-weight:700;
    }
    div{
        color:green;
        font-size:30px;
    }
</style>

<!-- 生效700加粗，30字号，绿色 -->
<div>div 标签</div>
~~~

#### 优先级

一个标签使用了多个选择器，优先级如下：

通配符选择器<标签选择器<类选择器<id选择器<行内选择器<!important

~~~html
<style>
   *{
    /* 把标签优先级提到最高 */
    color: red !important;
   }
</style>
~~~

（选中标签范围越大，优先级越低）

~~~html
<style>
   *{
    color: red;
   }

   div{
    color:green;
   }
</style>

<!-- 标签选择器优先级大于通配符选择器，文字变绿 -->
<div>div 标签</div>
~~~



### 盒子模型

| 盒子模型      | 备注                                                         |
| ------------- | ------------------------------------------------------------ |
| padding       | 内边距，在文本和盒子边缘之间生成一个边框，会撑大盒子<br />box-sizing:border-box; **内减模式，不会撑大** |
| border        | 边框线                                                       |
| margin        | 外边距，生成在盒子外面，不会撑大盒子<br />argin：0 auto；**保证版心居中，即左右外边距相等** |
| border-radius | 外边框设置为圆角                                             |
| box-shadow    | 盒子外边框有阴影                                             |

~~~html
<style>
    div{
        width: 500px;
        height: 500px;
        background-color:red;

        padding: 20px;
        box-sizing:border-box;
        
        border: 1px solid #000;
        /* solid:实线，dashed:虚线，dotted:点线 */
        
        margin: 50px;
        argin:0 auto;
        
        border-radius: 10px 20px 40px 80px;
        /* 左上，右上，右下，左下 */                                                                                     
        box-shadow: 2px 5px 10px 1px rgba(0,0,0,0.5);
        
    }
</style>

<div>div标签</div>
~~~



#### 模型属性

| 边框线                            | 备注     |
| --------------------------------- | -------- |
| border-top(bdt)                   | 上边框线 |
| border-right                      | 右边框线 |
| border-bottom                     | 下边框线 |
| border-left                       | 左边框线 |
| solid:实线 dashed:虚线 otted:点线 |          |

  **内边距/外边距 写法同上**



#### 元素溢出处理

~~~html
<style>
	overflow:auto;
</style>
~~~

| 属性   | 备注                                 |
| ------ | ------------------------------------ |
| hidden | 隐藏溢出                             |
| scroll | 溢出内容滚动显示，无论是否溢出都滚动 |
| auto   | 溢出内容滚动显示，自动显示滚动条     |



###  Flex布局

作用：块级转行内块

#### 创建flex容器

设置方式：给父元素设置 **display：flex**，子元素会自动转换成行内块，自动挤压或拉伸

~~~html
<style>

    /* 整个弹性容器 */
    .box{
        /* 自动调整样式 */
        display: flex;  
	    
        height: 500px;
        width: 500px;
        border: 1px solid #000;
    }

    /* 每一个弹性盒子 */
    /* 后代选择器 */
    .box div{
    height: 100px;
    width: 200px;
    background-color:green;
    }   
</style>

<div class="box">
    <div>1</div>
    <div>2</div>
    <div>3</div>
</div>
~~~



#### 主轴对齐方式

属性名：

~~~html
<style>
	justify-content:flex-start;
</style>
~~~

| 属性值        | 备注                                                     |
| ------------- | -------------------------------------------------------- |
| flex-start    | 弹性盒子左对齐（默认）                                   |
| flex-end      | 弹性盒子右对齐                                           |
| center        | 弹性盒子沿主轴居中排列                                   |
| space-between | 弹性盒子沿主轴均匀排列，空白间距均匀分布在盒子**之间**   |
| space-around  | 弹性盒子沿主轴均匀排列，空白间距均匀分布在盒子**两侧**   |
| space-evenly  | 弹性盒子沿主轴均匀排列，盒子与盒子、盒子与容器距离都相同 |



#### 侧轴对齐方式

属性名：

~~~html
<style>
	align-items:flex-start;
    /* 给弹性容器内的所有弹性盒子设置侧轴对齐方式 */
    
    align-self:flex-start;
    /* 给某个弹性盒子设置侧轴对齐方式 */
    
</style>
~~~

| 属性值     | 备注                   |
| ---------- | ---------------------- |
| flex-start | 上对齐                 |
| flex-end   | 下对齐                 |
| center     | 居中排列               |
| stretch    | 弹性盒子沿侧轴铺满容器 |



#### 修改主/侧轴方向

~~~html
<style>
	flex-direction:column;
    /* 改主轴为垂直、侧轴为水平 */
</style>
~~~



#### 弹性伸缩比

默认情况下，主轴方向尺寸靠内容撑开，侧轴方向默认拉伸完整个弹性盒子

~~~html
<style>
    div:nth-child(1){
	flex:1;
        
	div:nth-child(2){
	flex:2;  
        
        /* 把弹性容器空间分成三份，分别占其中的一份和两份 */
    }
</style>
~~~



#### 弹性盒子内换行

弹性盒子默认自动挤压或拉伸

~~~css
<style>
	flex-wrap:wrap;
</style>
~~~



#### 行对齐方式

属性名：

~~~html
<style>
	align-content:flex-start;
</style>
~~~



**让每一行以主轴对齐的方法沿侧轴对齐的方式对齐**

| 属性值        | 备注                                                     |
| ------------- | -------------------------------------------------------- |
| flex-start    | 弹性盒子对齐（默认）                                     |
| flex-end      | 弹性盒子右对齐                                           |
| center        | 弹性盒子沿主轴居中排列                                   |
| space-between | 弹性盒子沿主轴均匀排列，空白间距均匀分布在盒子**之间**   |
| space-around  | 弹性盒子沿主轴均匀排列，空白间距均匀分布在盒子**两侧**   |
| space-evenly  | 弹性盒子沿主轴均匀排列，盒子与盒子、盒子与容器距离都相同 |



### 标签定位

#### 相对定位/绝对定位

子类绝对路径，父类相对路径**（子绝父相）**，再设置绝对路径的偏移量即可**实现标签重叠**

~~~html
<style>
    .div{
       position:relative; /* 给定相对位置 */ 
    }
    
    .div div{
        position:absolute; /* 给定绝对位置 */
        
        top:0;
        right:0;
        /* 到右上角 */
    }
</style>
~~~



#### 定位盒子水平垂直都居中

~~~html
div{
	position: absolute;
	left:50%;
	top:50%;
	transform: translate(-50%,-50%);
}
~~~



#### 固定定位

~~~html
div{
	position:fixed;
}
~~~



#### 堆叠层级

后来者居上

~~~html
div{
	z-index:1;
}
/* 数字越大，层级越靠上 */
~~~





### 字体图标

展示的是图标，实际上是字体。<a href="https://www.iconfont.cn/">字体图标下载</a>

使用方法：

1.引入字体样式表（iconfont.css）,引入方式用外部样式表

~~~html
@font-face{
	font-famliy:"iconfont"; /* 字体名称 */
	src:url('iconfont.woff2?t=16837283888') format('woff2');
}
~~~

2.标签使用字体图标的类名

​	① iconfont：字体图标的基本样式（字体名，字体大小等）

​	②icon-xxx：图标对应的类名

~~~html
<span class="iconfont icon-xxx"></span>
~~~



### css设计小技巧

#### 垂直对齐方式

作用：将图片和文字对齐显示

属性名（谁比较大就把属性赋值给谁）：

~~~html
img{
	vertical-align:middle;
}
~~~



| 属性值   | 备注             |
| -------- | ---------------- |
| baseline | 基线对齐（默认） |
| top      | 顶部对齐         |
| middle   | 居中对齐         |
| bottom   | 底部对齐         |



#### 过渡效果

作用：一个元素切换另一种状态过程时添加过渡效果

transition属性设置给元素本身

~~~html
<style>
    img{
	width:200px;
    height:200px;
    transition: all 1s;
    }
    
    img:hover{
	width:200px;
    height:200px; 
    }

</style>
~~~



#### 透明度

属性名：opacity

（完全透明）0->1（不透明）



#### 鼠标样式

属性名：cursor

~~~html
div{
	cursor:text;
}
~~~



| 属性值  | 备注                   |
| ------- | ---------------------- |
| default | 默认值，箭头           |
| pointer | 小手效果，提示点击     |
| text    | 工字形，提示输入       |
| move    | 十字光标，提示可以移动 |


























































































# Vue上手

## 是什么

Vue是一个用于构建用户界面的**渐进式**框架

~~~mermaid
graph
声明式渲染-->组件系统-->客户端路由VueRouter-->大规模状态管理Vuex-->构建工具Webpack/Vite
~~~

## 创建实例

- 准备容器
- 引包（开发版本或生产版本）
  - [V2官网](https://v2.cn.vuejs.org)
  - [V3官网](https://cn.vuejs.org)
- 创建vue实例 new Vue()
- 指定配置顶->渲染数据
  - el指定挂载点
  - data提供数据



- ~~~html
  <body>
  
    <!-- 创建盒子容器，在之后用于渲染代码逻辑 -->
    <div id="app">
      <!-- 要渲染的数据的标识 -->
      <h1>{{msg}}</h1>
      <a href="#">{{count}}</a>
    </div>
  
  
    <!--  引开发版本包，包含完整的注释和警告-->
    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.16/dist/vue.js"></script>
  
  
    <script>
      // 引入了Vue核心包之后，在全局环境就包含了vue的构造函数
      // 创建实例
      const app = new Vue({
        // 通过el配置选择器，指定Vue管理的是哪一个盒子
        el: '#app',
  
        //通过data提供要渲染的数据
        data: {
          msg: 'Hello',
          count: 666
        }
      })
    </script>
  
  </body>
  ~~~



## 插值表达式 {{}}

- 插值表达式是Vue的一种**模板语法**，插值表达式里面**会返回一个文本结果**，不具备解析标签的能力

- 作用是给定文本一个标签，就可以通过标签对文本进行渲染处理

- 注意事项（**错误使用案例**）：

  - 使用的数据必须存在

    ~~~html
    <p>{{ 一个不存在的数据 }}</p>
    ~~~

  - 支支持文本，不支持语句（如if，for）

    ~~~html
    <p>{{ if }}</p>
    ~~~

  - 不能再标签属性中使用插值表达式，**这只是一个文本！！！**

    ~~~html
    <p title="{{ username }}"> 我是p标签 </p>
    ~~~

    

# Vue指令

- Vue指令就是一个特殊的标签属性（v-前缀）

  - 普通标签属性

    ~~~html
    <div title="AAA"> </div>
    ~~~

  - Vue指令（特殊标签属性）

    ~~~html
    <div v-html="str"> </div>
    ~~~

    

## v-html

- 动态设置元素的innerHTML（**任意修改文本**）
- v-html = "表达式"

- 使用案例，把href标签设置成一个模板字符串

  ~~~html
  <body>
    <div id="app">
      <div v-html="msg"></div>
    </div>
  
    <!--  引开发版本包，包含完整的注释和警告-->
    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.16/dist/vue.js"></script>
  
  
    <script>
      const app = new Vue({
        el: '#app',
        data: {
          msg: `
          <a href="https://www.baidu.com">百度</a>
          `
        }
      })
  
    </script>
  ~~~





## v-show&&v-if

- 相同处

  - 都是控制元素显示和隐藏

  - 语法都是`v-show = "表达式"`,`v-if = "表达式"`

  - 都是表达式true显示，表达式false隐藏

    

- 不同点

  - `v-show`隐藏的时候是使用`display:none`来隐藏

  - `v-if`隐藏的时候是完全移除

    

- 使用场景

  - `v-show`适用于需要频繁切换显示和隐藏的场景
  - `v-if`适用于不用频繁切换的场景

 

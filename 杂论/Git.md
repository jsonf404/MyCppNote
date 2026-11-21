# Git

> 开发常用，帮助开发者记录和跟踪代码的变化。个人重要资料也可以存放在远程仓库如 `github`、`gitee` 中防止丢失。

> 本文介绍一些常用方法 and 一些简单的 `git` 操作，小白个人使用足矣。



## 创建仓库

> 以 `github` 为例，`gitee` 操作差不多。



### 创建团队系统

GitHub 的“团队系统”一般是通过 **Organization（组织）** 来实现的，它支持多个成员、多个仓库、权限分配等。

1. 登录你的 GitHub（https://github.com）。
2. 点击右上角头像 → 选择 **Your organizations**。
3. 点击右上角的 **“New organization”** 按钮。
4. 选择免费方案（Free Plan）。
5. 填写组织信息：
   - **Organization account name**：组织名称（比如 `myteam`）
   - **Email**：组织邮箱（可以用你的个人邮箱）
6. 点击 **Create organization**。



### 添加团队成员

1. 进入刚创建的组织主页。
2. 点击顶部的 **“Teams”** → **New team**。
3. 填写团队名（如 `dev-team`），可以设置：
   - 权限：是否能推送代码、管理项目等。
   - 可见性：公开还是仅组织成员可见。
4. 创建后点击团队 → **Add a member** → 输入成员 GitHub 用户名邀请加入。



### 创建代码仓库（Repository）

1. 进入你的组织页面（例如 `https://github.com/myteam`）。
2. 点击右上角 **New repository**。
3. 设置：
   - **Repository name**：仓库名（例如 `team-project`）
   - **Description**：项目说明
   - **Visibility**：公开（Public）或私有（Private）
   - 可选：勾选 “Add a README file”
4. 点击 **Create repository**。





## 上传代码

> 安装好 `git` 就行，都是一套代码



### 新仓库第一次传

1. **假设你本地已经有一个项目文件夹，在项目根目录打开命令行**

```bash
cd 路径/到/你的项目文件夹
```



2. **初始化 git 仓库**

```bash
git init
```



3. **添加文件**

```bash
git add .
```



4. 提交到本地

```bash
git commit -m "first commit"
```



5. **绑定远程仓库，这个网址一般就在仓库里可以复制**

```bash
git remote add origin https://github.com/myteam/team-project.git
```

---

```bash
# 可选：删除已经绑定的远程仓库
git remote remove origin
```



6. **推送本地分支到远程同名分支（第一次可能需要登录），**

   **如果你的本地分支是 master，则将 `main` 改为 `master`，本地远程分支名尽量一样**

```bash
git push -u origin main
```

---

```bash
# 可选：强制修改当前分支名称
git branch -M main

# 可选：查看所有分支
git branch -a

# 可选：创建并切换分支，不要 -b 就是切换到已有分支
git checkout -b new-branch-name
```



### 本地修改后上传

1. **进入本地仓库**

```bash
cd 路径/到/你的项目文件夹
```

---

```bash
# 可选：查看哪些文件被修改、添加或删除
git status
```



2. **添加文件**

```bash
git add .
```

---

```bash
# 可选：只添加特定文件
git add filename1.txt filename2.js
```



3. **提交修改到本地仓库，然后上传**

```bash
git commit -m "fix: 修复用户登录失败的问题"

# 推送到远程仓库（首次后可以简化为 git push）
git push origin main
```



### 远程拉仓库改了再传

```cpp
# 克隆仓库
git clone https://github.com/myteam/team-project.git

# 进入项目目录
cd team-project

# 修改代码后推送
git add .
git commit -m "修改的信息"
git push orn main
```

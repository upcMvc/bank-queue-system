![logo](/img/LOGO.png)   
# 银行排队系统     

## 项目介绍:

   本项目设计并实现了银行排队取号系统的一系列功能。包括客户取号，柜台叫号及业务办理信息查询。显示器显示当前时间及排队情况，用户通过点击取号按钮获取排队号码。柜员通过输入账号及密码进入操作页面，实现叫号、重复叫号及用户星级评价等功能，经理通过输入账号及密码登录经理界面，监管当前业务办理情况，可以模拟银行业务厅的叫号排队问题的处理。 本项目各模块之间的通信标准请参考[数据接发标准](/syn.txt)。

   

## 模块介绍:
 * 用户取号模块
 * 柜员操作模块
 * 经理显示模块

#### 用户取号模块

功能介绍：
* 普通/VIP用户获取业务办理号码 
* 显示当前排队信息及柜台叫号信息
* 显示当前时间

![取号UI界面](/img/1.png)

#### 柜员操作模块

功能介绍：
* 柜员登录认证
* 叫号/重新叫号
* 请求用户评价

![柜员UI界面](/img/2.png)


#### 经理显示模块

功能介绍：
* 显示历史/当前排队信息，柜台业务处理信息
* 显示用户对柜员 的评价信息
* 当前时间显示

![取号UI界面](/img/3.png)

## license
[MIT](LICENSE) 



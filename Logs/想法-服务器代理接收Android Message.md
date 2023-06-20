## 微信QQ消息代理

原理设想  
在服务器部署QQ,微信的服务,登陆 个人账号  
通过API调用或者第三方SDK来监听QQ,微信的消息  
最后通过服务器转发到手机端  
手机端APP后台常驻来代替QQ,微信的后台进程,实现轻量化的消息推送  

### 一些参考

通过 Matrix 协议实现代理接收 QQ 和微信消息  
SmsForwarder转发器  
pc-wechat-hook-http-api劫持消息  
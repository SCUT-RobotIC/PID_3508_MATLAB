# PID_3508_MATLAB
使用matlab搭建pid速度环/角度环模型并直接生成C代码部署


PID 更新时间为0.001秒

调参建议搭配Cube Monitor


*部分已知道的问题*

尚未解决如何驱动多个电机的问题/模型重复使用也许可以/ : 结论：可以，暂未发现新的问题 -> 使用coder的多实例生成

角度环下的积分误差会不断累积 ： 解决方案，加一个switch模块位于PID输入前 （未修复）| 目前由于积分上限限制没出问题，但是不知道实际是否会出现问题（有空修）






# 关于simulink中快速部署PID，及其种类选择的简单介绍。

+ 感谢毛雍齐同学提供的IP方面的帮助

### Main.slx

这个模型大致介绍simulink中常用的PID模块，以及一些变体。

#### Tips:

+ 在实际使用过程中，我们常常会发现simulink自带的pid很难满足我们的一些需求，（抗扰动，不超调等功能）因此我推荐之后使用的PID模块采用手工搭建的等效，参考Main.slx中的模型，抗饱和可以手工搭建，其实挺简单的。

+ 使用IP CONTROL来避免超调，具体介绍将会在下文介绍。

+ Simulink中的2DOF PID , 即二自由度PID模块，具体介绍将会在下文介绍。

+ 增量式PID，该方法的具体优势是由于本身算法的问题，消除了整个系统中累积的积分误差，即，在面对需要抗饱和的环节中，效果可能会好一点。具体实现参考Increment_test.slx。

### IP CONTROL

这里我们只考虑角度环的情况，即含积分系统 (积分延迟系统)，并忽略实际系统存在输出上限的情况（通常这种情况只能通过对参数的放缩解决）。

假设，你已经通过[cyatar/PID-Controller-Design-for-Integrating-Systems (github.com)](https://github.com/cyatar/PID-Controller-Design-for-Integrating-Systems)

该项目获得了你觉得响应比较好的参数。

但是，一般来讲，电机的角度环模型可以近似成这个![](C:\Users\james\Desktop\TP\images\2024-05-17-09-38-35-image.png)

你可以看见有零点产生的超调。

好，那么好，假设你的实际应用中不能用超调该怎么办。

请参考IP.slx中提供的模型，

- 本质是等效的进行了一个低通滤波，但是代价会降低系统频宽（-3db）

- 因此你不能照搬参数，需要修改

- IP.slx模型中提供了5个模型，分别对应

- 1. STEP输入的PI控制器
  
  2. RAMP输入的PI控制器
  
  3. STEP输入的IP控制器
  
  4. STEP输入的加了低通滤波的PI控制器
  
  5. STEP输入的IP控制器，加快了响应，注意这里的参数，所以实际上一个乘K一个乘上K^2就可以。（通过改变K的值来弥补前面降低的系统频宽）

## 二自由度PID控制器模块

即Main.slx最后使用的PID模块。

+ 什么是二自由度PID // 二自由度控制器 (Two degree-of-freedom controllers)中，每个自由度分别处理抗扰和跟踪任务，从根本上克服了单自由度控制器的固有缺陷，是一种实用的控制算法设计方法。取决于另一自由度控制器在控制系统中所处位置，二自由度控制器可以分为两大类：前馈+反馈，干扰观测器+反馈；你可以看见模型中旁边贴了关于这个模块的等效，具体请参考该模块的文档。

+ 有什么用，理论上来说，该模块可以通过参数的调整替代PID，或者IPD的功能，人话来讲，就是如果你想实现IP控制之类没有超调/减少超调的办法，可以不用手搭。
  
  参考[Specify PI-D and I-PD Controllers - MATLAB & Simulink - MathWorks 中国](https://ww2.mathworks.cn/help/slcontrol/ug/create-i-pd-and-pi-d-controllers.html?requestedDomain=cn)

+ 从频域来说，前馈应该和干扰观测器存在某种等效。

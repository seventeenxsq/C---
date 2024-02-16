# C++ Game
C++制作的小游戏( 图形库基于 easyx库)

大二课程设计作业
author: Seventeen Xu 
![image](https://github.com/seventeenxsq/CPP-Game-gaze/assets/50203389/f5aae0f1-0243-468e-9b28-6bc06b1a272f)

演示: https://www.bilibili.com/video/BV1BA4m1G7mJ/

# 游戏玩法设计:
地图是隐藏的，人物只能看见周边的地图，需要在收集3个药水道具![image](https://github.com/seventeenxsq/CPP-Game-gaze/assets/50203389/e6b66f67-bf0e-4b8a-97a1-40ae69dac86c)

走到长老处![image](https://github.com/seventeenxsq/CPP-Game-gaze/assets/50203389/e37752b7-2d0f-4e9d-a9d5-b058e7309c1c)

![image](https://github.com/seventeenxsq/CPP-Game-gaze/assets/50203389/83da1192-18b9-473d-9505-ee91f2900d42)
 可以扩大视野
 
![image](https://github.com/seventeenxsq/CPP-Game-gaze/assets/50203389/5f19d8ae-a672-459c-88c9-6a997b0679ab)
 可以增加速度
素材来自于泡泡堂


# 类的设计

**GameClass**该类定义了游戏开始界面，胜利界面，欢迎界面以及插进不同音乐等功能
+ GameClass():void
+ ~GameClass():void
+ WelcomeActivity():void
+ HaveWin():void
+ Run():void
  
**RoleClass类的设计**
该类通过转换人物坐标为矩阵值，实现了判断人物是否撞墙等功能。
RoleClass
+ steplength:int
+ IfCrash: bool
+ TransformX (int):int
+ TransformY (int):int
+ RoleClass ():void
+ ~RoleClass ():void
   
**PlayerClass类的设计**
PlayerClass类，包含地图的显示、判断人物是否碰撞、判断人物行走的前方是否为道具、道具的判别以及捡拾道具后人物属性的变化、游戏初开始与游戏胜利的提示框以及判断是否游戏胜利等功能的实现。
PlayerClass:public RoleClass
+ x:int
+ y:int
+ direction:int
+ sight:int
+ countWater:int
+ imageSize:int
+ PaintRoad(int,int,int):void
+ IfCrash(int):bool
+ KeyDown_Coordinates():void
+ isWin():bool 
+ return_X(int): int
+ return_Y(int): int
+ PutImage (int):void
+ getPrize (int):void
+ changeSelf (int):void
+ GameInfo ():void
-role: IMAGE
-roleY: IMAGE


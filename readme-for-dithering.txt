Floyd–Steinberg dithering

顾名思义，误差扩撒，就是色彩深度降低时，将像素的变化的误差扩撒开去，
使得肉眼在观察图片的时候，相邻的像素点集合整体的误差变小，
就比如：人在下楼梯时，如果台阶过高，容易扯着蛋；要是同样的高度能多有几个台阶，
那么台阶之间的距离变小了，那么扯蛋效应就会减小甚至消失（不好意思，我称之为扯蛋效应）。
--------------------- 
作者：hujingshuang 
来源：CSDN 
原文：https://blog.csdn.net/hujingshuang/article/details/45716445 
版权声明：本文为博主原创文章，转载请附上博文链接！

伪代码如下：
for each y from top to bottom
   for each x from left to right
      oldpixel  := pixel[x][y]
      newpixel  := find_closest_palette_color(oldpixel)
      pixel[x][y]  := newpixel
      quant_error  := oldpixel - newpixel
      pixel[x + 1][y    ] := pixel[x + 1][y    ] + quant_error * 7 / 16
      pixel[x - 1][y + 1] := pixel[x - 1][y + 1] + quant_error * 3 / 16
      pixel[x    ][y + 1] := pixel[x    ][y + 1] + quant_error * 5 / 16
      pixel[x + 1][y + 1] := pixel[x + 1][y + 1] + quant_error * 1 / 16
Floyd�CSteinberg dithering

����˼�壬�������������ɫ����Ƚ���ʱ�������صı仯�����������ȥ��
ʹ�������ڹ۲�ͼƬ��ʱ�����ڵ����ص㼯�����������С��
�ͱ��磺������¥��ʱ�����̨�׹��ߣ����׳��ŵ���Ҫ��ͬ���ĸ߶��ܶ��м���̨�ף�
��ǫ̂��֮��ľ����С�ˣ���ô����ЧӦ�ͻ��С������ʧ��������˼���ҳ�֮Ϊ����ЧӦ����
--------------------- 
���ߣ�hujingshuang 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/hujingshuang/article/details/45716445 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

α�������£�
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
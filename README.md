# 双三次B样条曲面网格状显示程序
> 运行环境：VC++6.0

 使用de Boor-Cox递推公式获得三次B样条基函数，通过读入的16个三维控制点变换为2维坐标，形成一个4x4矩阵，达到C2连续性。

B样条曲线及其性质

![image](https://user-images.githubusercontent.com/61911969/175793674-5ebbd098-c5bb-486e-b0d2-e2e55af80b43.png)

上式中，Pi(i=0,…,n)是控制点，Ni,k(i=0,…,n)是第i个k阶B样条基函数。B样条基函数是分段k次（k+1阶）多项式，它们由节点向量唯一决定，节点向量则是一串非减的实数序列。

该程序为均匀B样条。节点成等差数列均匀分布，这样的节点分布对应的是均匀B样条基函数，三次B样条基函数如图所示：

![image](https://user-images.githubusercontent.com/61911969/175793795-1289f873-7c3c-460b-b8c6-d4ffcfa728fb.png)


双三次B样条曲面是由三次B样条曲线交织而成。曲面生成时先固定u, 变化v得到一簇三次B样条曲线；然后固定v，变化u得到另一簇三次B样条曲线。
**单源最短路问题可以使用 Dijkstra 算法，其核心思路是贪心算法。流程如下：**

1. 首先，Dijkstra 算法需要从当前全部未确定最短路的点中，找到距离源点最短的点 xx。

2. 其次，通过点 xx 更新其他所有点距离源点的最短距离。例如目前点 A 距离源点最短，距离为 3；有一条 A->B 的有向边，权值为 1，那么从源点先去 A 点再去 B 点距离为 3 + 1 = 4，若原先从源点到 B 的有向边权值为 5，那么我们便可以更新 B 到源点的最短距离为 4。

3. 当全部其他点都遍历完成后，一次循环结束，将 xx 标记为已经确定最短路。进入下一轮循环，直到全部点被标记为确定了最短路。
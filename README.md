# 学生管理系统（1.0~5.0）
- 声明1：本人对一切抄袭行为概不负责，，，之后会考虑用go和mysql再写一个。
- 声明2：不保证没有任何bug。
- 声明3：并没有按照题目的要求在写，，，后果自负。1.0已经用了结构体了。
- 声明4：真要找答案建议去CSDN。放这里只是提供个思路。
- 声明5：代码显然还可以优化。改良主义的可以考虑把冒泡直接改成快排，或者直接用qsort()/sort()（当然，sort是c艹里的东西）。还有Search那块也能修改优化。但是这里最多就30个人，所以我直接暴力过了，，，
- 声明6：今天突然想起来我冒泡全写错了。懒得改了，能过学校的样例就是。两种可能：能排序，或者运气好。有点懒，不想细究原因了，大概是后者。有心的可以改过来（雾）。
- 另外number一开始就该搞成全局变量，，，懒得改了。这样也行。
- 这里写函数更多是为了功能的分治（换句话说，方便debug）而不是复用。当然还能更加细分，不过也没考虑那么多了。那个Swap()函数倒是专门为了复用去用的。另外为了减少工作量所以我bubble函数和search函数实际上加了好几个状态，这好几个状态都调用一个函数。
- 复用的最好例子其实应该是我写的那个message-board。比如处理error信息的时候就在不断调用util里的东西。其它的倒是比较专一化了。

- 更新了5.0。没看到5.0？反正你直接复制4.0是过不了4.0的。

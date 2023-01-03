# Backtracking

## Core
1. 本质上是一种暴力穷举
2. 穷举的过程就是遍历一颗多叉树的过程

## Frame

在某个节点上，只需要思考
1. 路径：已经做出的选择
2. 选择列表：当前可以做的选择
3. 结束条件：在决策树的底层

pseudocode (Cited from Labuladong)
```C++
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        排除不可以做的选择
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```


# data-structure-study

数据结构与算法学习代码（C 语言实现）。

## 文件说明

| 文件 | 内容 |
|------|------|
| `linear_list-1.c` | 顺序表（数组实现） |
| `linear_list-2.c` | 单链表 |
| `linear_list-3.c` | 双向链表 |
| `kmp.c` | KMP 字符串匹配算法 |
| `ADT-study-1.c` | 抽象数据类型练习 |
| `recursion-test.c` | 递归经典题 |
| `shangji-1.c` | 上机实验 1 |
| `shangji-2.c` | 上机实验 2 |
| `homework-1.c` | 课后作业 1 |
| `homework-2.c` | 课后作业 2 |

## 主要内容

- **线性表** — 顺序表、单链表、双向链表的增删改查
- **KMP 算法** — 字符串模式匹配，O(n+m) 时间复杂度
- **递归** — 经典递归问题（汉诺塔、斐波那契等）

## KMP 核心思路

```
next 数组记录模式串的最长公共前后缀长度
匹配失败时利用 next 跳过已匹配部分，避免重复比较
时间复杂度：O(n + m)，优于暴力匹配 O(n×m)
```

## 编译运行

```bash
gcc -o kmp kmp.c && ./kmp
```

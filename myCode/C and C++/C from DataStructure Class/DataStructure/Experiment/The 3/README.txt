查找与排序

该程序构造比较简单，功能单一，我将直接展示代码的运行结果：

单词数统计（选取前10个单词展示）：
[Word]the
    Num :4255

[Word]to
    Num :1911

[Word]a
    Num :1888

[Word]of
    Num :1884

[Word]and
    Num :1483

[Word]in
    Num :1155

[Word]it
    Num :846

[Word]is
    Num :787

[Word]
    Num :764

[Word]that
    Num :758

字母数统计（同上，选取前十个结果）：
[Word]             //空格
    Num :63522

[Word]e
    Num :38455

[Word]t
    Num :27835

[Word]a
    Num :23925

[Word]o
    Num :23173

[Word]i
    Num :20941

[Word]n
    Num :20448

[Word]s
    Num :19871

[Word]r
    Num :17686

[Word]h
    Num :16869

程序介绍：
使用了实验一有关链表的库函数
程序运行的流程为，从文本获取字符串->去掉字符串末尾可能会出现的符号->按顺序插入链表->基于重复次数对链表进行排序->打印结果

时间复杂度分析：
上述流程最为复杂的便是对整个得到的链表进行排序，这里我们只需要分析排序步骤的时间复杂度即可

由于我使用的是冒泡排序，因此本程序的时间复杂度为O（n^2）

其中n为非重复的单词数量
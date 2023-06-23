    Init();

    Node *Main = New_Node();
    Set_Name(Main, "学生管理系统");
    Set_Message(Main, "2023年数据结构课程实验解决方案");
    Set_Number_Selection(Main, 4);
    Set_Selection(Main, "查看学生信息", 0, 1, 0);
    Set_Selection(Main, "查找学生信息", 1, 1, 1);
    Set_Selection(Main, "退出", 2, 0, 0);
    Set_Selection(Main, "    ", 3, 3, 0);
    

    Node *SubMain_1 = New_Node();
    Set_Name(SubMain_1, "学生信息");
    Set_Message(SubMain_1, "1.李思尧\n2.霍博一\n3.马天驰");
    Set_Number_Selection(SubMain_1, 2);
    Set_Selection(SubMain_1, "返回", 0, 2, 0);
    Set_Selection(SubMain_1, "退出", 1, 0, 0);
    

    Node *SubMain_2 = New_Node();
    Set_Name(SubMain_2, "查找信息");
    Set_Message(SubMain_2, "Message");
    Set_Number_Selection(SubMain_2, 3);
    Set_Selection(SubMain_2, "返回", 0, 2, 0);
    Set_Selection(SubMain_2, "退出", 1, 0, 0);
    Set_Selection(SubMain_2, "啊?", 2, 0, 0);
    

    Connect_Node(Main, SubMain_1, 0);
    Connect_Node(Main, SubMain_2, 1);

    Current_pNode = Main;
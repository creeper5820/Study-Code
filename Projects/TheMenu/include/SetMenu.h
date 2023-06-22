    Init();

    Node *Main = New_Node();
    Set_Name(Main, "Main");
    Set_Message(Main, "Message");
    Set_Selection(Main, "SubMain_1", 0, 1, 0);
    Set_Selection(Main, "SubMain_2", 1, 1, 1);
    Set_Selection(Main, "Function_3", 2, 0, 0);
    Set_Selection(Main, "Function_4", 3, 0, 0);
    Set_Number_Selection(Main, 4);

    Node *SubMain_1 = New_Node();
    Set_Name(SubMain_1, "SubMain_1");
    Set_Message(SubMain_1, "Message");
    Set_Selection(SubMain_1, "1", 0, 2, 0);
    Set_Selection(SubMain_1, "2", 1, 0, 0);
    Set_Number_Selection(SubMain_1, 2);

    Node *SubMain_2 = New_Node();
    Set_Name(SubMain_2, "SubMain_2");
    Set_Message(SubMain_2, "Message");
    Set_Selection(SubMain_2, "1", 0, 2, 0);
    Set_Selection(SubMain_2, "2", 1, 0, 0);
    Set_Selection(SubMain_2, "3", 2, 0, 0);
    Set_Number_Selection(SubMain_2, 3);

    Connect_Node(Main, SubMain_1, 0);
    Connect_Node(Main, SubMain_2, 1);

    Current_pNode = Main;
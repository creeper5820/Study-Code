    Init();

    Node *Main = New_Node();
    Set_Name(Main, "The System");
    Set_Message(Main, "2023 Datastructure");
    Set_Number_Selection(Main, 4);
    Set_Selection(Main, "Show the message", 0, 1, 0);
    Set_Selection(Main, "Find the message", 1, 1, 1);
    Set_Selection(Main, "exit", 2, 0, 0);
    Set_Selection(Main, "egg", 3, 3, 0);
    

    Node *SubMain_1 = New_Node();
    Set_Name(SubMain_1, "Message");
    Set_Message(SubMain_1, "1.Lisii\n2.Boer\n3.MTC");
    Set_Number_Selection(SubMain_1, 2);
    Set_Selection(SubMain_1, "back", 0, 2, 0);
    Set_Selection(SubMain_1, "exit", 1, 0, 0);
    

    Node *SubMain_2 = New_Node();
    Set_Name(SubMain_2, "Find");
    Set_Message(SubMain_2, "Message");
    Set_Number_Selection(SubMain_2, 3);
    Set_Selection(SubMain_2, "back", 0, 2, 0);
    Set_Selection(SubMain_2, "exit", 1, 0, 0);
    Set_Selection(SubMain_2, "Ha?", 2, 0, 0);
    

    Connect_Node(Main, SubMain_1, 0);
    Connect_Node(Main, SubMain_2, 1);

    Current_pNode = Main;
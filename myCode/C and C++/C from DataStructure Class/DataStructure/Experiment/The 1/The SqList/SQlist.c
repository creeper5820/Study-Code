#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    float score;
} student;

typedef struct {
    student *data;
    int length;
    int capacity;
} student_table;

// 初始化学生管理表
void init_table(student_table *table, int capacity) {
    table->data = (student*)malloc(capacity * sizeof(student));
    table->length = 0;
    table->capacity = capacity;
}

// 释放学生管理表内存
void free_table(student_table *table) {
    free(table->data);
    table->data = NULL;
    table->length = 0;
    table->capacity = 0;
}

// 打印学生信息
void print_student(student s) {
    printf("Name: %s\nNUmber: %d\nScore: %.2f\n", s.name, s.id, s.score);
}

// 逐个输入学生信息
void input_students(student_table *table) {
    int capacity = table->capacity;
    int i = table->length;
    while (i < capacity) {
        printf("Student %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", table->data[i].name);
        printf("NUmber: ");
        scanf("%d", &table->data[i].id);
        printf("Score: ");
        scanf("%f", &table->data[i].score);
        printf("\n");
        i++;
        table->length++;
        printf("Continue to input? (y/n)");
        char c;
        scanf(" %c", &c);
        if (c == 'n' || c == 'N') {
            break;
        }
    }
}

// 逐个显示所有学生信息
void print_students(student_table *table) {
    printf("\nStudent Information:\n");
    printf("Total: %d students\n\n", table->length);
    int i;
    for (i = 0; i < table->length; i++) {
        printf("Student %d:\n", i+1);
        print_student(table->data[i]);
        printf("\n");
    }
}

// 根据姓名查找学生
student *find_student(student_table *table, char *name) {
    int i;
    for (i = 0; i < table->length; i++) {
        if (strcmp(table->data[i].name, name) == 0) {
            return &table->data[i];
        }
    }
    return NULL;
}

// 根据位置查找学生
student *get_student_at(student_table *table, int index) {
    if (index < 0 || index >= table->length) {
        return NULL;
    }
    return &table->data[index];
}

// 插入学生信息
void insert_student(student_table *table, int index, student s) {
    if (index < 0 || index > table->length || table->length == table->capacity) {
        return;
    }
    int i;
    for (i = table->length-1; i >= index; i--) {
        table->data[i+1] = table->data[i];
    }
    table->data[index] = s;
    table->length++;
}

// 删除学生信息
void delete_student(student_table *table, int index) {
    if (index < 0 || index >= table->length) {
        return;
    }
    int i;
    for (i = index+1; i < table->length; i++) {
        table->data[i-1] = table->data[i];
    }
    table->length--;
}

// 统计学生个数
int count_students(student_table *table) {
    return table->length;
}

int main() {
    student_table table;
    int capacity;
    printf("Input student count: ");
    scanf("%d", &capacity);
    init_table(&table, capacity);
    input_students(&table);
    print_students(&table);
    int index;
    char name[50];
    printf("Find student by name: ");
    scanf("%s", name);
    student *s = find_student(&table, name);
    if (s != NULL) {
        printf("Result:\n");
        print_student(*s);
    } else {
        printf("Student not found.\n");
    }
    printf("Get student at index: ");
    scanf("%d", &index);
    s = get_student_at(&table, index);
    if (s != NULL) {
        printf("Result:\n");
        print_student(*s);
    } else {
        printf("Invalid index.\n");
    }
    student new_student;
    printf("Insert a new student:\n");
    printf("Name: ");
    scanf("%s", new_student.name);
    printf("NUmber: ");
    scanf("%d", &new_student.id);
    printf("Score: ");
    scanf("%f", &new_student.score);
    printf("Insert at index: ");
    scanf("%d", &index);
    insert_student(&table, index, new_student);
    print_students(&table);
    printf("Delete student at index: ");
    scanf("%d", &index);
    delete_student(&table, index);
    print_students(&table);
    printf("Student count: %d\n", count_students(&table));
    free_table(&table);
    return 0;
}
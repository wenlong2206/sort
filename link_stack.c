/*
	带有头结点的链栈
*/

// 导入包
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// 自定义数据类型
typedef struct Element
{
	char id[14];
	char name[41];
	int price;
} ElementType;


typedef struct LinkStack
{
	ElementType element;
	struct LinkStack* next;
} LinkStackType;



// 自定义链栈

LinkStackType* init_stack(void)
{
	LinkStackType* p_stack = (LinkStackType*)malloc(sizeof(LinkStackType));
	
	if (p_stack == NULL)
	{
		printf("Memory space development failed and is located in line %d of file %s.", __LINE__, __FILE__);
		abort();
	}
	p_stack->next = NULL;

	return p_stack;
}


int destroy_stack(LinkStackType* p_stack)
{
	assert(p_stack != NULL);
	
	LinkStackType* p_next = p_stack->next;
	while (p_next)
	{
		LinkStackType* p_temp = p_next;
		p_next = p_next->next;
		free(p_temp);
		p_stack->next = NULL;
	}
	free(p_stack);
	p_stack = NULL;

	return 1;
}


int clear_stack(LinkStackType* p_stack)  // 清空返回1
{
	assert(p_stack != NULL);

	LinkStackType* p_next = p_stack->next;  // __OKOKOK__
	while (p_next)
	{
		LinkStackType* p_temp = p_next;
		p_next = p_next->next;
		free(p_temp);
		p_stack->next = NULL;  // __OKOKOKOKO__
	}

	return 1;  // 返回第一个节点
}


int is_empty(LinkStackType* p_stack)
{
	if (p_stack->next == NULL)
		return 1;  // 空栈
	else
		return 0;  // 非空栈
}


int length_stack(LinkStackType* p_stack)  // 长度
{
	assert(p_stack != NULL);

	int count = 0;
	while (p_stack = p_stack->next)
	{
		++count;
	}

	return count;
}


ElementType get_top(LinkStackType* p_stack)
{
	assert(p_stack != NULL);
	
	LinkStackType* p_next = p_stack->next;
	if (p_next != NULL)
	{
		ElementType top = p_next->element;
		return top;
	}
	else
	{
		printf("The chain stack is empty and is located on line %d of the file %s.", __LINE__, __FILE__);
		abort();
	}
}


int push(LinkStackType* p_stack, ElementType* p_element)
{
	assert(p_stack != NULL);
	assert(p_element != NULL);

	LinkStackType* p_node = (LinkStackType*)malloc(sizeof(LinkStackType));
	if (p_node == NULL)
	{
		printf("Memory space development failed and is located in line %d of file %s.", __LINE__, __FILE__);
		abort();
	}

	LinkStackType* p_temp = p_stack->next;
	p_node->element = *p_element;
	p_stack->next = p_node;
	p_node->next = p_temp;

	return 1;
}


ElementType pop(LinkStackType* p_stack)
{
	assert(p_stack != NULL);

	LinkStackType* p_temp = p_stack->next;
	ElementType top = p_temp->element;
	p_stack->next = p_temp->next;
	free(p_temp);

	return top;
}

/*
int main(void)
{
	LinkStackType arr[] = {
		{"9787302257646", "程序设计基础", 25},
		{"9787302219972", "单片机技术及应用", 32},
		{"9787302203513", "编译原理", 46},
		{"9787811234932", "汇编语言程序设计教程", 21}
	};

	LinkStackType* p_stack = init_stack();
	int i = 0;
	for (i = 0; i < 4; i++)
		push(p_stack, arr + i);

	//ElementType d = pop(p_stack);
	//printf("%s, %s, %d\n\n", d.id, d.name, d.price);

	//ElementType d = get_top(p_stack);
	//printf("%s, %s, %d\n\n", d.id, d.name, d.price);

	//while (p_stack = p_stack->next)
	//{
	//	ElementType data = p_stack->element;
	//	printf("%s, %s, %d\n", data.id, data.name, data.price);
	//}

	//int l = length_stack(p_stack);
	//printf("%d\n", l);
	
	//int l = is_empty(p_stack);
	//printf("%d\n", l);

	//clear_stack(p_stack);
	destroy_stack(p_stack);


}

*/


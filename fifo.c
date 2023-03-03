/*
 * Page Replacement Algorithm
 * FIFO - First In First Out
 * Default Page Frame = 4
 * Oishik Mukhopadhyay | 03 March 2023
 */

#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_PAGE_FRAMES 4
#define ALGORITHM "FIFO"

typedef struct _frame_buffer
{
	int* pages;
	int frames;
} frame_buffer;

void init_frame_buffer(frame_buffer* buffer)
{
	buffer->pages = (int*)malloc(buffer->frames * sizeof(int));
	int i;
	for(i=0; i<buffer->frames; i++)
	{
		buffer->pages[i] = 0;
	}
}

void set_frames(frame_buffer* buffer, int frame_size)
{
	buffer->frames = frame_size;
}

int check_page_in_table(frame_buffer* buffer, int page_id)
{
	int i, retval = -1;
	for(i=0; i<buffer->frames; i++)
	{
		if(buffer->pages[i] == page_id)
		{
			retval = i;
		}
	}
	return retval;
}

void print_table(frame_buffer* buffer)
{
	int i;
	printf("\nTable : ");
	for(i=0; i<buffer->frames; i++)
	{
		printf("%d ", buffer->pages[i]);
	}
	printf("\n");
}

void fifo(frame_buffer* buffer, int page_id)
{
	printf("\nReceived new page : %d.", page_id);
	int retval = check_page_in_table(buffer, page_id); 
	if(retval == -1)
	{
		printf("\nPage Fault. ");
		int last_element_index = buffer->frames - 1;
		int last_element = buffer->pages[last_element_index];
		int i;
		for(i=last_element_index; i>=1; i--)
		{
			buffer->pages[i] = buffer->pages[i-1];
		}
		if(last_element != 0)
		{
			printf("Removed from table : %d.", last_element);
		}
		buffer->pages[0] = page_id;
	}
	else
	{
		printf("\nTable intact. Page %d found at index %d.", page_id, retval);
	}
	print_table(buffer);
}

int main()
{
	frame_buffer fifo_buffer;
	set_frames(&fifo_buffer, DEFAULT_PAGE_FRAMES);
	init_frame_buffer(&fifo_buffer);
	fifo(&fifo_buffer, 1);
	fifo(&fifo_buffer, 2);
	fifo(&fifo_buffer, 3);
	fifo(&fifo_buffer, 4);
	fifo(&fifo_buffer, 5);
	fifo(&fifo_buffer, 5);
	fifo(&fifo_buffer, 4);
	fifo(&fifo_buffer, 3);
	fifo(&fifo_buffer, 2);
	fifo(&fifo_buffer, 1);
	return 0;
}

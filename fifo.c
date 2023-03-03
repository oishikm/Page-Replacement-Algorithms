/*
 * Page Replacement Algorithm
 * FIFO - First In First Out
 * Default Page Frame = 4
 * Oishik Mukhopadhyay | 03 March 2023
 */

#include"pagehandler.h"

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
	int* pages_queue;
	int i, pages_queue_size;
	printf("\nEnter pages queue size : ");
	scanf(" %d", &pages_queue_size);
	printf("\nEnter pages queue of size %d : ", pages_queue_size);
	pages_queue = (int *)malloc(pages_queue_size * sizeof(int));
	for(i=0; i<pages_queue_size; i++)
	{
	    scanf(" %d", &pages_queue[i]);
	}
	for(i=0; i<pages_queue_size; i++)
	{
	    fifo(&fifo_buffer, pages_queue[i]);
	}
	return 0;
}

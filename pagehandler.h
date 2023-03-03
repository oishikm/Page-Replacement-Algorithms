/*
 * Page Handling Header
 * Default Page Frame = 4
 * Oishik Mukhopadhyay | 03 March 2023
 */

#pragma once
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

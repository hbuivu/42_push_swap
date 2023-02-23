#include "push_swap.h"

void	quick_sort(int *array, int min, int max)
{
	int	pivot;
	int	temp;
	int	i;
	int	j;

	if (min == max)
		return ;
	pivot = array[min];
	i = min;
	j = max;
	while (i <= j)
	{
		while (i < pivot)
			i++;
		while (j > pivot)
			j--;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	temp = pivot;
	array[min] = array[j];
	array[j] = temp;
	quick_sort(array, min, j-1);
	quick_sort(array, j+1, max);
}

//the brute force way that will work every time
void	find_pivots(t_nlist **list_a, t_nlist **list_b, t_dlist *d)
{
	t_nlist	*cur;
	int		*sort_array;
	int		i;
	int		bucket_len;

	sort_array = (int *)ft_calloc(d->len, sizeof(int));
	if (!sort_array)
		//free all lists and exit
	i = 0;
	cur = *list_a;
	while (i < d->len)
	{
		sort_array[i++] = cur->num;
		cur = cur->next;
	}
	quick_sort(sort_array, 0, d->len - 1);
	bucket_len = d->len / d->buckets;
	//fill out pivots
	d->pivots[0] = d->min;
	d->pivots[d->buckets] = d->max + 1;
	i = 1;
	while (i < d->buckets)
		d->pivots[i++] = sort_array[bucket_len * i]; 
	//fill out subpivots
	i = 0;
	while (i < d->buckets - 1)
		d->pivots[i++] = sort_array[(bucket_len / 2) * i];
}

//the quick way that won't work with outliers
void	find_pivots(t_nlist **list_a, t_nlist **list_b, t_dlist *d)
{
	int	i;
	int	range;

	i = 0;
	range = ((d->max - d->min) / d->buckets) + 1;
	while (i <= d->buckets)
		d->pivots[i++] = d->min + (i * range);
	i = 0;
	while (i < d->buckets)
		d->subpivots[i++] = d->min + ((range / 2) * (i + 1));
}

//the super long way that is prob too complicated
//start out with pivots as follows
	//range = max - min / buckets
	//bucket_len = len_list(list_a) / buckets;
	//[min, min + (i)range, ...., max + 1];
	//create an array of size len of list;
	//check first bucket in array to see if it falls withing +-5 of bucket len;
	//if it does -> done, don't need to fix pivots
	
	//if it does not, sort bucket 
	//if too large -
		//truncate at bucket len, and note down that pivot
		//push remaining numbers back to list
		//recalculate range with remaining numbers and refill out pivot array 
	//if too small - 
		//push over other numbers
	//repeat last three steps from above
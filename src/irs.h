/* 
 * Created by Micael Dias on 10/12/20.
 */

#ifndef IRS_H
#define IRS_H

#include "memory.h"

#define CSV_COLUMN_DELIMITER ','
#define CSV_NEW_LINE_DELIMITER '\n'
#define CSV_BUFFER 50
#define MAX_DEPENDENT_NUMBER 6

typedef enum
{
	H_IRS_UP_TO,
	H_IRS_BEYOND
} e_type;

typedef struct
{
	e_type monthly_pay_type;
	float monthly_pay_value;
	float* percentage_per_dependent;
} s_irs;

typedef struct
{
	s_irs* data;
	int used;
	int max_capacity;
} s_arr_irs;

typedef void (* h_irs_pair_func)(s_irs*, char*, int*);

s_arr_irs* h_irs_alloc(int initial_capacity);
void h_irs_free(s_arr_irs* array);
void h_irs_parse(s_arr_irs* array, const char* str, h_irs_pair_func pair_func);
void h_irs_write(s_arr_irs* array, const char* path);
void h_irs_add(s_arr_irs* array);
void h_irs_delete(s_arr_irs* array, int index);
void h_irs_print_line(s_irs data);
void h_irs_print(s_arr_irs* array);
void h_irs_edit(s_arr_irs* array, int index);
void h_irs_build(s_irs* data, char* str, int* dependent);

#endif //IRS_H

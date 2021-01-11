#include <stdio.h>

#include "util.h"
#include "irs.h"
#include "iss.h"
#include "menu.h"

#define INITIAL_CAPACITY 50

int main_menu()
{
	int op;

	s_arr_irs* single_array;
	s_arr_irs* unique_holder_array;
	s_arr_irs* two_holders_array;
	s_arr_iss* iss_array;
	s_arr_employees* employees_array;
	s_spreadsheet* spreadsheet = NULL; // Processamento Salarios

	/*
	 * IRS
	 * ---------------------------------------------------------------------------------------------------------
	 */
	single_array = h_irs_alloc(INITIAL_CAPACITY);
	if (single_array == NULL)
	{
		return -1;
	}

	unique_holder_array = h_irs_alloc(INITIAL_CAPACITY);
	if (unique_holder_array == NULL)
	{
		free(single_array);
		return -1;
	}

	two_holders_array = h_irs_alloc(INITIAL_CAPACITY);
	if (two_holders_array == NULL)
	{
		free(single_array);
		free(unique_holder_array);
		return -1;
	}

	/*
	 * Segurança Social
	 * ---------------------------------------------------------------------------------------------------------
	 */
	iss_array = h_iss_alloc(INITIAL_CAPACITY);
	if (iss_array == NULL)
	{
		free(single_array);
		free(unique_holder_array);
		free(two_holders_array);
		return -1;
	}

	/*
	 * Gestão de Funcionários
	 * ---------------------------------------------------------------------------------------------------------
	 */
	employees_array = h_employees_alloc(INITIAL_CAPACITY);
	if (employees_array == NULL)
	{
		free(single_array);
		free(unique_holder_array);
		free(two_holders_array);
		free(iss_array);
		return -1;
	}

	do
	{
		fprintf(stdout, "%s", H_STRS_MENU);
		op = h_util_get_int(0, 9, "Opção?");

		switch (op)
		{
			case 1:
				h_menu_irs(single_array, unique_holder_array, two_holders_array);
				break;
			case 2:
				h_menu_iss(iss_array);
				break;
			case 3:
				h_menu_employees(employees_array, iss_array);
				break;
			case 4:
				h_menu_processing(single_array,
					unique_holder_array,
					two_holders_array,
					iss_array,
					employees_array,
					spreadsheet);
				break;
			case 5:
				h_menu_reports(employees_array, spreadsheet);
				break;
			case 8:
				// TODO: Carregar Tudo -> quando tiver as funções load
			case 9:
				// TODO: Guardar Employees, Processamento
				h_irs_write(single_array, H_PATH_SINGLE);
				h_irs_write(unique_holder_array, H_PATH_UNIQUE_HOLDER);
				h_irs_write(two_holders_array, H_PATH_TWO_HOLDERS);
				h_iss_write(iss_array, H_PATH_SEG_SOCIAL);
				break;
			default:
				break;
		}
	} while (op != 0);

	h_irs_free(single_array);
	h_irs_free(unique_holder_array);
	h_irs_free(two_holders_array);
	h_iss_free(iss_array);
	return 0;
}

int main()
{
	return main_menu();
}

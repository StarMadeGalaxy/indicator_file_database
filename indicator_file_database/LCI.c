#pragma once

#include "LCI.h"
#include "iotools.h"


void lci_menu(void)
{
	puts("-----------------------����-----------------------\n");
	puts("1. �������� ����������� � ������");
	puts("2. ����� ����������� �� �����");
	puts("3. ���������� ������ � ����� �����������");
	puts("4. �������� ������ �� ����� �����������");
	puts("5. ������������� ������ � ��������� �������");
	puts("6. ����� ������ �� ������������� ��������� ����");
	puts("7. ���������� ���������/����������� � ����");
	puts("8. �������� ����������� �� �����");
	puts("9. ���������� ������� �������� �� ���������� ����,");
	puts("   ���������� ������� ������ �� ��������� ����");
	puts("10. ����� �� ���������");
	puts("-----------------------����-----------------------");
}


void lci_find(LCI* indicators, const size_t amount)
{
	if (amount <= 0)
	{
		puts("\n���������� ����.");
		return;
	}
	if (indicators == NULL)
	{
		puts("\n���������� ����� NULL");
		return;
	}

	char input[MAX];

	puts("\n�������� ���� �� ������ �������� ����������� �����\n");
	puts("1. ����� ����������");
	puts("2. �����������");
	puts("3. ����������������� �����");
	puts("4. ��������");
	printf("\n������� ��������: ");

	getline(input);
	size_t menu_choice = (size_t)string_to_int(input);

	if (menu_choice < 1 || menu_choice > 4)
	{
		puts("\n������������ ��������. ���������� ������.");
		return;
	}

	char new_value[MAX];
	printf("\n������� �������� ��� ������: ");
	getline(new_value);

	short is_found = 0;

	switch (string_to_int(input))
	{
	case RESERVOIR:
		if (if_int_string(new_value) == 1)
		{
			double reservoir = (double)string_to_int(new_value);

			for (size_t i = 0; i < amount; i++)
			{
				if (indicators[i].reservoir == reservoir)
				{
					printf("\n#%zu � �������: %lf", i, reservoir);
					lci_info(&indicators[i]);
					is_found = 1;
				}
			}
		}
		else {
			puts("������������ ��������. ���������� ������.");
			return;
		}
		break;
	case TEMPERATURE:
		if (if_int_string(new_value) == 1)
		{
			double temperature = (double)string_to_int(new_value);

			for (size_t i = 0; i < amount; i++)
			{
				if (indicators[i].temperature == temperature)
				{
					printf("\n#%zu � ������������: %lf", i, temperature);
					lci_info(&indicators[i]);
					is_found = 1;
				}
			}
		}
		else {
			puts("������������ ��������. ���������� ������.");
			return;
		}
		break;
	case LIFESPAN:
		if (if_int_string(new_value) == 1)
		{
			double lifespan = (double)string_to_int(new_value);

			for (size_t i = 0; i < amount; i++)
			{
				if (indicators[i].lifespan == lifespan)
				{
					printf("\n#%zu � ������������������ �����: %lf", i, lifespan);
					lci_info(&indicators[i]);
					is_found = 1;
				}
			}
		}
		else {
			puts("������������ ��������. ���������� ������.");
			return;
		}
		break;
	case INDICATOR:
		for (size_t i = 0; i < amount; i++)
		{
			if (string_equality(indicators[i].indicator, new_value) == 1)
			{
				printf("\n#%zu � ���������: %s", i, new_value);
				lci_info(&indicators[i]);
				is_found = 1;
			}
		}

		break;
	default:
		puts("\n������ ������ � ���� ���!");
		break;
	}
	if (is_found == 0)
		puts("\n������ �� �������.");
	else
		puts("\n����� �������� �������!");
}
	

void lci_correct(LCI* indicators, const size_t amount)
{
	if (amount <= 0)
	{
		puts("\n������ ����!");
		return;
	}
	if (indicators == NULL)
	{
		puts("\n���������� ����� NULL");
		return;
	}

	char input[MAX];

	printf("\n������� ����� ����������, ������� ������ ��������: ");
	getline(input);
	if (if_int_string(input) == 0)
	{
		puts("\n������� ����������� ��������. ���������� ������.");
		return;
	}

	size_t num_to_correct = (size_t)string_to_int(input);

	if (num_to_correct >= amount)
	{
		puts("\n����� ��������� ���������� ���������.");
		return;
	}
	
	puts("\n�������� ���� ��� ���������\n");
	puts("1. ����� ����������");
	puts("2. �����������");
	puts("3. ����������������� �����");
	puts("4. ��������");
	printf("\n������� ��������: ");

	getline(input);
	size_t menu_choice = (size_t)string_to_int(input);
	
	if (menu_choice < 1 || menu_choice > 4)
	{
		puts("\n������������ ��������. ���������� ������.");
		return;
	}

	char new_value[MAX];
	printf("\n������� ����� ��������: ");
	getline(new_value);

	switch (string_to_int(input))
	{
	case RESERVOIR:
		if (if_int_string(new_value) == 1)
		{
			indicators[num_to_correct].reservoir = (double)string_to_int(new_value);
		}
		else {
			puts("������������ ��������. ���������� ������.");
			return;
		}
		break;
	case TEMPERATURE:
		if (if_int_string(new_value) == 1)
		{
			indicators[num_to_correct].reservoir = (double)string_to_int(new_value);
		}
		else {
			puts("������������ ��������. ���������� ������.");
			return;
		}
		break;
	case LIFESPAN:
		if (if_int_string(new_value) == 1)
		{
			indicators[num_to_correct].reservoir = (double)string_to_int(new_value);
		}
		else {
			puts("������������ ��������. ���������� ������.");
			return;
		}
		break;
	case INDICATOR:
		memcpy(indicators[num_to_correct].indicator, new_value, MAX);
		break;
	default:
		puts("\n������ ������ � ���� ���!");
		break;
	}
	puts("\n��������� ������ �������!");
}


void swap_lci(LCI* frst, LCI* snd)
{
	double temp = 0;

	swap_strings(frst->indicator, snd->indicator);

	temp = frst->lifespan;
	frst->lifespan = snd->lifespan;
	snd->lifespan = temp;

	temp = frst->reservoir;
	frst->reservoir = snd->reservoir;
	snd->reservoir = temp;

	temp = frst->temperature;
	frst->temperature = snd->temperature;
	snd->temperature = temp;
}


LCI* lci_file_read(FILE* fptr, const char* filename, size_t* amount)
{
	errno_t error_code;
	error_code = fopen_s(&fptr, filename, "rb");

	if (error_code != 0) {
		printf("������ �������� ����� '%s'.\n���� ������ ������������ ����� �������.\n\n", filename);
		return 0;
	}
	else
	{
		printf("���� '%s' ������ ������� ��� ������.\n\n", filename);
	}

	size_t lci_file_amount = get_file_size(fptr, filename) / sizeof(LCI);
	LCI* indicators = (LCI*)malloc(lci_file_amount * sizeof(LCI));

	if (lci_file_amount > MAX)
	{
		puts("\n���������� ����������� ��������� ���������� ������ �����������.");
		puts("� ����� ����� �������� ������������ ���������� �����������.\n");
		lci_file_amount = MAX;
	} 
	else if (lci_file_amount <= 0)
	{
		puts("\n������ ����!");
		return 0;
	}

	if (indicators != NULL)
	{
		for (size_t i = 0; i < lci_file_amount; i++)
		{
			if (fread(&indicators[i], sizeof(LCI), 1, fptr) == 0)
			{
				printf("\n�� ����� ������ ��������� ������.\n�������� ����� �� ������� �����������\n");
				break;
			} else {
				printf("��������� '%s' �������� ������� �� ����� '%s'.\n", indicators[i].indicator, filename);
			}
		}
	}

	fclose(fptr);
	*amount = lci_file_amount;

	return indicators;
}


void lci_file_write(FILE* fptr, const char* filename, LCI* indicators, size_t lci_num)
{
	if (lci_num <= 0)
	{
		puts("\n������ ����!");
		return;
	}

	errno_t error_code;

	error_code = fopen_s(&fptr, filename, "wb");

	if (error_code != 0) {
		printf("������ �������� ����� '%s'.\n\n", filename);
		return;
	}
	else
	{
		printf("���� '%s' ������ ������� ��� ������.\n\n", filename);
	}

	for (size_t i = 0; i < lci_num; i++) 
	{
		printf("��������� '%s' ������� ������� � ���� '%s'.\n", indicators[i].indicator, filename);
		fwrite(&indicators[i], sizeof(LCI), 1, fptr);
	}
	fclose(fptr);
}


LCI* lci_delend(LCI* indicators, size_t* amount)
{
	if (amount <= 0)
	{
		puts("\n������ ����!");
		return indicators;
	}
	if (indicators == NULL)
	{
		puts("\n���������� ����� NULL");
		return indicators;
	}

	char input[MAX];

	printf("\n������� ���������� ����������� ������� ������ �������: ");
	getline(input);

	if (if_int_string(input) == 0)
	{
		puts("\n������� ����������� ��������. ���������� ������.");
		return indicators;
	}

	size_t how_much = (size_t)string_to_int(input);

	if (((signed)*amount - (signed)how_much) < 0)
	{
		puts("\n�������� ������� ������. ���������� ������.");
		return indicators;
	}
	else if ((*amount - how_much) == 0)
	{
		free(indicators);
		puts("\n���������� ������.");
		return NULL;
	}

	LCI* temp_lci = (LCI*)realloc(indicators, sizeof(LCI) * (*amount - how_much));
	if (temp_lci != NULL)
	{
		indicators = temp_lci;
	}
	else
	{
		puts("\n������ ���������� ��� ��������.");
		return NULL;
	}
	*amount -= how_much;
	puts("\n�������� ������ �������!");
	return indicators;
}


LCI* lci_append(LCI* indicators, size_t* amount)
{
	char input[MAX];

	printf("\n������� ���������� ����������� ������� ������ ��������: ");
	getline(input);

	if (if_int_string(input) == 0)
	{
		puts("\n������� ����������� ��������. ���������� ������.");
		return indicators;
	}

	size_t how_much = (size_t)string_to_int(input);

	if ((*amount + how_much) >= MAX)
	{
		puts("\n�������� ������� ������. ���������� ������.");
		return indicators;
	}

	LCI* temp_lci = (LCI*)realloc(indicators, sizeof(LCI) * (*amount + how_much));
	if (temp_lci != NULL)
	{
		indicators = temp_lci;
	}
	else 
	{
		puts("\n������ ���������� ��� ��������.");
		return NULL;
	}

	for (size_t i = *amount; i < *amount + how_much; i++)
	{
		system("CLS");

		LCI indicator;

		printf("\n������� ��� �������� ����������: ");
		getline(input);
		memcpy(indicator.indicator, input, MAX);

		printf("\n������� ����� ����������: ");
		getline(input);
		indicator.reservoir = (double)string_to_int(input);

		printf("\n������� �����������: ");
		getline(input);
		indicator.temperature = (double)string_to_int(input);

		printf("\n������� ����������������� �����: ");
		getline(input);
		indicator.lifespan = (double)string_to_int(input);

		indicators[i] = indicator;		// TODO: buffer overflow warning
	}
	*amount += how_much;
	puts("\n���������� ������ �������!");
	return indicators;
}


void lci_bubble_sort(LCI* indicators, const size_t size)
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (string_compare(indicators[j].indicator, indicators[j + 1].indicator)) {
				swap_lci(&indicators[j], &indicators[j + 1]);
			}
		}
	};
}


void lci_selection_sort(LCI* indicators, const size_t size, size_t mode)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t min_index = i;

		for (size_t j = i + 1; j < size; j++)
		{
			switch (mode)
			{
			case RESERVOIR:
				if (indicators[j].reservoir < indicators[min_index].reservoir)
					min_index = j;
				break;
			case TEMPERATURE:
				if (indicators[j].temperature < indicators[min_index].temperature)
					min_index = j;
				break;
			case LIFESPAN:
				if (indicators[j].lifespan < indicators[min_index].lifespan)
					min_index = j;
				break;
			default:
				break;
			}
		}
		swap_lci(&indicators[min_index], &indicators[i]);
	}
}


void sort_by_field(LCI* indicators, const size_t size)
{
	if (size <= 0 )
	{
		puts("\n������ ����!");
		return;
	} 
	if (indicators == NULL)
	{
		puts("\n���������� ����� NULL");
		return;
	}

	puts("�������� ���� ��� ����������: \n");
	puts("1. ��������");
	puts("2. ����� ����������");
	puts("3. �����������");
	puts("4. ����������������� �����");
	printf("\n������� ��������: ");

	char input[MAX];
	getline(input);

	switch (string_to_int(input))
	{
	case 1:
		lci_bubble_sort(indicators, size);
		break;
	case 2:
		lci_selection_sort(indicators, size, RESERVOIR);
		break;
	case 3:
		lci_selection_sort(indicators, size, TEMPERATURE);
		break;
	case 4:
		lci_selection_sort(indicators, size, LIFESPAN);
		break;
	default:
		puts("\n������ ������ � ���� ���!");
		break;
	}
	puts("\n���������� ������ �������!");
}


void lci_info(LCI* indicator)
{
	printf("\n���������: %s", indicator->indicator);
	printf("\n���������: %lf", indicator->reservoir);
	printf("\n�����������: %lf", indicator->temperature);
	printf("\n���� ������: %lf\n", indicator->lifespan);
}


void lci_array_output(LCI* indicators, const size_t size)
{
	if (size <= 0) 
	{
		puts("\n���������� ����.");
		return;
	}
	if (indicators == NULL)
	{
		puts("\n���������� ����� NULL");
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		printf("\n#%zu", i);
		lci_info(&indicators[i]);
	}
}


LCI* create_lci_array(LCI* indicators, size_t* amount)
{
	if (indicators != NULL)
	{
		puts("\n���������� ��� ��� ������. ��� ���������� ����������� ���������� � �����.\n");
		return indicators;
	}
	char input[MAX];

	printf("\n������� ���������� ����������� ������� ������ ��������: ");
	getline(input);
	if (if_int_string(input) == 0)
	{
		puts("\n������� ����������� ��������. ���������� ������.");
		return NULL;
	}
	size_t size = (size_t)string_to_int(input);
	*amount += size;
	indicators = (LCI*)malloc(*amount * sizeof(LCI));

	if (indicators)		// ���� ������� ������
	{
		for (size_t i = 0; i < size; i++)
		{
			system("CLS");

			LCI indicator;

			printf("\n������� ��� �������� ����������: ");
			getline(input);
			memcpy(indicator.indicator, input, MAX);

			printf("\n������� ����� ����������: ");
			getline(input);
			indicator.reservoir = (double)string_to_int(input);

			printf("\n������� �����������: ");
			getline(input);
			indicator.temperature = (double)string_to_int(input);

			printf("\n������� ����������������� �����: ");
			getline(input);
			indicator.lifespan = (double)string_to_int(input);

			indicators[i] = indicator;		// TODO: buffer overflow warning
		}
	}

	puts("\n�������� ���������!");
	return indicators;
}



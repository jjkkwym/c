#include "stdio.h"
#include "cJSON.h"

void json_creat(char *buf)
{
    cJSON * root =  cJSON_CreateObject();

    cJSON_AddStringToObject(root, "PartNumber", "0000000001");
    cJSON_AddStringToObject(root, "Unique serial number", "0202107161");
    cJSON_AddStringToObject(root, "Model", "0000000001");
    cJSON_AddStringToObject(root, "Hardware Initial Version", "0000000101");
    cJSON_AddStringToObject(root, "Data Pack Initial Version", "0000000101");
    cJSON_AddStringToObject(root, "Maker", "0000000001");
    cJSON_AddStringToObject(root, "FCC", "0000000001");
    cJSON_AddStringToObject(root, "Manufacture Date", "0000000000");
    cJSON_AddStringToObject(root, "Project ID", "0202107161");
    cJSON_AddStringToObject(root, "MB Number", "0000000001");
    cJSON_AddStringToObject(root, "FW Version", "1.0.21.0716");
    cJSON_AddStringToObject(root, "Device Type", "1");
    cJSON_AddStringToObject(root, "Provision Status", "0");

    sprintf(buf,"%s", cJSON_Print(root));
    printf("%s",buf);
    cJSON_Delete(root);
}

void json_parse(char *buf)
{
    cJSON * root = NULL;
    cJSON * data = NULL;
    root = cJSON_Parse(buf);
    if(!root)
    {
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());
    }
    else
    {
        printf("%s\n\n", cJSON_Print(root));
        //printf("%s\n\n", cJSON_PrintUnformatted(root));

        data = cJSON_GetObjectItem(root, "PartNumber");
        printf("type:%x,%s:",data->type ,data->string);
        printf("%s\n", data->valuestring);
        cJSON_ReplaceItemInObject(root,"PartNumber",cJSON_CreateString("123456"));
        data = cJSON_GetObjectItem(root, "PartNumber");
        printf("%s:", data->string);
        printf("%s\n", data->valuestring);
        data = cJSON_GetObjectItem(root, "Unique serial number");
        printf("%s:", data->string);
        printf("%s\n", data->valuestring); 
    }
    printf("%s", cJSON_Print(root));
}

int main()
{
    char buf[2048];
    json_creat(buf);
    json_parse(buf);
    return 0;    
}
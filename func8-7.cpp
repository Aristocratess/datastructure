void Visit(Record* r)
{
	printf("(%s,%d)",r->key.ch,r->others.order);
}

void InputKey(char *k)
{
	scanf("%s",k);
}

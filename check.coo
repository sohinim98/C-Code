const Assignment* dueIn(const HomeworkQueue* q, const int numDays)
{
	if(q == NULL) {
		Assignment* ass = new Assignment;
		ass->course = Null;
		return ass;
	}
	int len = 1;
	int c=0;
	Assignment* list = new Assignment[len];
	
	struct tm *theTime;
	time_t tim;
	time(&tim);
	theTime = localtime(&tim);
	int currentMonth = theTime ->tm_mon+1;
	int currentDay = theTime ->tm_mday;
	
	HomeworkQueue que = *q;
	HomeworkQueue* curr = &que;
	
	while(curr != NULL) {
		int months = curr->assn->dueMonth - currentMonth;
		int days;
		months *= 30;
			days = curr->assn->dueDay - currentDay;
			
			if(days <= numDays) {
				if(c == 0){
					list[0] = *curr->assn;
					c++;
				}
				else {
					Assignment* copy = new Assignment[len];
					for(int i=0;i<len;i++) {
						copy[i] = list[i];
					}
					list = new Assignment[len+1];
					for(int i=0; i<len;i++) {
						list[i] = copy[i];
					}
					list[len] = *curr->assn;
					len++;
				}
			}
			curr = curr->nextInQueue;
	}
	Assignment* ass = new Assignment[1];
	ass->course = Null;
	if(curr == NULL && c == 0) {
		return ass;
	}
	Assignment *temp = new Assignment[len];
	for(int i=0;i<len;i++) {
		temp[i] = list[i];
	}
	list = new Assignment[len+1];
	for(int i=0;i<len;i++) {
		list[i] = temp[i];
	}
	list[len] = ass[0];
	return list;
	
}
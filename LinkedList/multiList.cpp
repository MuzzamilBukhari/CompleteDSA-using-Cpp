#include <iostream>
using namespace std;

struct StudentNode
{
  int studentID;
  StudentNode *next;
};

struct CourseNode
{
  int courseID;
  StudentNode *studHead;
  CourseNode *next;
};

void addCourse(CourseNode **courseHead, int courseID)
{
  CourseNode *ptr = (CourseNode *)malloc(sizeof(CourseNode));
  ptr->courseID = courseID;
  ptr->studHead = NULL;
  ptr->next = NULL;
  if (*courseHead == NULL)
  {
    *courseHead = ptr;
    cout << "Course is added in a list " << endl;
    return;
  }
  CourseNode *curr = *courseHead;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }
  curr->next = ptr;
  cout << "Course is added in a list " << endl;
}

void deleteCourse(CourseNode **courseHead, int courseID)
{
  if (*courseHead == NULL)
  {
    cout << "Course List is empty " << endl;
    return;
  }
  if (courseID == (*courseHead)->courseID)
  {
    CourseNode *tmp = *courseHead;
    *courseHead = (*courseHead)->next;
    free(tmp);
    cout << "Course SUccessfully Deleted " << endl;
    return;
  }
  CourseNode *prev = *courseHead;
  CourseNode *curr = prev->next;
  while (curr != NULL)
  {
    if (curr->courseID == courseID)
    {
      prev->next = curr->next;
      free(curr);
      cout << "Course Successfully Deleted " << endl;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  cout << "Course not found in the list " << endl;
}

CourseNode *searchCourse(CourseNode *courseHead, int courseID)
{
  CourseNode *curr = courseHead;
  while (curr != NULL)
  {
    if (curr->courseID == courseID)
      return curr;
    curr = curr->next;
  }
  return NULL;
}

void printCourseList(CourseNode *courseHead)
{
  if (courseHead == NULL)
  {
    cout << "Course list is empty " << endl;
    return;
  }
  CourseNode *curr = courseHead;
  while (curr != NULL)
  {
    cout << "Course " << curr->courseID << endl;
    curr = curr->next;
  }
}

void addStudToCourse(CourseNode **courseHead, int courseID, int studentID)
{
  CourseNode *isCourse = searchCourse(*courseHead, courseID);
  if (isCourse)
  {
    StudentNode *ptr = (StudentNode *)malloc(sizeof(StudentNode));
    ptr->studentID = studentID;
    ptr->next = NULL;
    if (isCourse->studHead == NULL)
    {
      isCourse->studHead = ptr;
      cout << "Student added in Course " << endl;
      return;
    }
    StudentNode *curr = isCourse->studHead;
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = ptr;
    cout << "Student added in Course " << endl;
  }
  else
  {
    cout << "Course not found in the list " << endl;
  }
}

void searchStudInCourse(CourseNode *courseHead, int courseId, int studId)
{
  CourseNode *isCourse = searchCourse(courseHead, courseId);
  if (isCourse)
  {
    if (isCourse->studHead == NULL)
    {
      cout << "0 students enroll in this course" << endl;
      return;
    }
    StudentNode *curr = isCourse->studHead;
    while (curr != NULL)
    {
      if (curr->studentID == studId)
      {
        cout << "Student found in the list" << endl;
      }
      curr = curr->next;
    }
    cout << "Student not found " << endl;
  }
  else
  {
    cout << "Course not found in the list " << endl;
  }
}

void deleteStudFromCourse(CourseNode **courseHead, int courseID, int studID)
{
  CourseNode *isCourse = searchCourse(*courseHead, courseID);
  if (isCourse)
  {
    if (isCourse->studHead == NULL)
    {
      cout << "0 students enroll in this course " << endl;
      return;
    }
    if (isCourse->studHead->studentID == studID)
    {
      StudentNode *tmp = isCourse->studHead;
      isCourse->studHead = isCourse->studHead->next;
      free(tmp);
      cout << "The student is successfully deleted from this course" << endl;
    }
    StudentNode *prev = isCourse->studHead;
    StudentNode *curr = isCourse->studHead->next;
    while (curr != NULL)
    {
      if (curr->studentID == studID)
      {
        prev->next = curr->next;
        free(curr);
        cout << "The student is successfully deleted from this course" << endl;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
    cout << "Student not found in this Course " << endl;
  }
  else
  {
    cout << "Course not found in the list " << endl;
  }
}

void deleteStudent(CourseNode **courseHead, int studID)
{
  if ((*courseHead) == NULL)
  {
    cout << "Course list is empty " << endl;
    return;
  }
  CourseNode *currCourse = *courseHead;
  while (currCourse != NULL)
  {
    if (currCourse->studHead == NULL)
    {
      cout << "Student not enroll in course " << currCourse->courseID << endl;
      currCourse = currCourse->next;
      continue;
    }
    if (currCourse->studHead->studentID == studID)
    {
      StudentNode *tmp = currCourse->studHead;
      currCourse->studHead = currCourse->studHead->next;
      free(tmp);
      cout << "The student is successfully deleted from course " << currCourse->courseID << endl;
      currCourse = currCourse->next;
      continue;
    }
    StudentNode *prev = currCourse->studHead;
    StudentNode *curr = prev->next;
    while (curr != NULL)
    {
      if (curr->studentID == studID)
      {
        prev->next = curr->next;
        free(curr);
        cout << "The student is successfully deleted from course " << currCourse->courseID << endl;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
    if (curr == NULL)
      cout << "Student not enroll in Course " << currCourse->courseID << endl;
    currCourse = currCourse->next;
  }
}

void printStudentsInCourse(CourseNode *courseHead, int courseID)
{
  CourseNode *isCourse = searchCourse(courseHead, courseID);
  if (isCourse)
  {
    if (isCourse->studHead == NULL)
    {
      cout << "0 students enroll in this course " << endl;
      return;
    }
    StudentNode *curr = isCourse->studHead;
    while (curr != NULL)
    {
      cout << "Student ID is " << curr->studentID << endl;
      curr = curr->next;
    }
  }
  else
  {
    cout << "Course not in the list" << endl;
  }
}

int main()
{
  CourseNode *courseHead = NULL;
  int n;
  do
  {
    cout << "Enter 1 to Add course " << endl
         << "Enter 2 to Delete course" << endl
         << "Enter 3 to Search course" << endl
         << "Enter 4 to Print courselist" << endl
         << "Enter 5 to Add Student to course" << endl
         << "Enter 6 to Search Student in a course" << endl
         << "Enter 7 to Delete student from course" << endl
         << "Enter 8 to Delete Student" << endl
         << "Enter 9 to Print list of students in course" << endl
         << "Enter 10 to Exit" << endl;
    cin >> n;
    if (n == 1)
    {
      int courseId;
      cout << "Enter course ID which you want to Add in a List : ";
      cin >> courseId;
      addCourse(&courseHead, courseId);
    }
    else if (n == 2)
    {
      int courseId;
      cout << "Alert !!! Deleting course ID will also delete all students data who entroll in this course" << endl;
      cout << "Enter Course ID which you want to Delete from a List : ";
      cin >> courseId;
      deleteCourse(&courseHead, courseId);
    }
    else if (n == 3)
    {
      int courseId;
      cout << "Enter course ID which you want to Search in a list : ";
      cin >> courseId;
      CourseNode *isCourse = searchCourse(courseHead, courseId);
      isCourse ? cout << "Yes Course " << isCourse->courseID << " is in the List " << endl : cout << "Course not in the List " << endl;
    }
    else if (n == 4)
    {
      printCourseList(courseHead);
    }
    else if (n == 5)
    {
      int courseID;
      cout << "Enter course ID in which you want to add student : ";
      cin >> courseID;
      int studID;
      cout << "Enter Student ID : ";
      cin >> studID;
      addStudToCourse(&courseHead, courseID, studID);
    }
    else if (n == 6)
    {
      int courseID;
      int studID;
      cout << "Enter Student ID you want to Search : ";
      cin >> studID;
      cout << "In which course you want to search this student : ";
      cin >> courseID;
      searchStudInCourse(courseHead, courseID, studID);
    }
    else if (n == 7)
    {
      int courseID;
      int studID;
      cout << "Enter Student ID you want to Delete : ";
      cin >> studID;
      cout << "In which course you want to delete this student : ";
      cin >> courseID;
      deleteStudFromCourse(&courseHead, courseID, studID);
    }
    else if (n == 8)
    {
      int studID;
      cout << "Enter Student ID which you want to Delete from all courses : ";
      cin >> studID;
      deleteStudent(&courseHead, studID);
    }
    else if (n == 9)
    {
      int courseID;
      cout << "Enter course ID to show the students entroll in this course : ";
      cin >> courseID;
      printStudentsInCourse(courseHead, courseID);
    }
    else if (n == 10)
    {
      cout << "Exit from multi list !!!" << endl;
    }
    else
    {
      cout << "Invalid!!!" << endl;
    }
  } while (n != 10);
}
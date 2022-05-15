#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);
static struct file *find_file_by_fd(int fd)
{
  struct thread *th = thread_current();

  return th -> fd_table[fd];
}

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  void halt(void)
  {
    power_off();
  }

  void exit(int st)
  {
    struct thread *th = thread_current();
    th -> exit_status = st;
    
    printf("%s: exit(%d)\n", thread_name(), st);
    thread_exit();
  }

  pid_t exec(const char *cmd_line)
  {
    
  }

  int wait(pid_t pid)
  {
    // child not exist -> return -1
    // 
  }

  bool create(const char *flie, unsigned initial_siez)
  {
    return filesys_create(file, initial_size);
  }

  bool remove(const char *file)
  {
    return filesys_remove(file);
  }

  int open(const char *file)
  {
    struct file *openfile = filesys_open(file);

    if(openfile == NULL)
    {
      return -1;
    }
  }

  int filesize(int fd)
  {
    struct file *openfile = find_file_by_fd(fd);

    return file_length(openfile);
  }

  int read(int fd, void *buffer, unsigned size)
  {
    struct file *openfile = find_file_by_fd(fd);
  }

  void seek(int fd, unsigned position)
  {
    struct file *openfile = find_file_by_fd(fd);
  }

  unsigned tell(int fd)
  {
    struct file *openfile = find_file_by_fd(fd);

    return file_tell(openfile);
  }

  void close(int fd)
  {
    struct file *openfile = find_file_by_fd(fd);
  }
}

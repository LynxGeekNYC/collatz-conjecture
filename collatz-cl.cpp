#include <iostream>
#include <CL/cl.h>

#define MAX_SOURCE_SIZE (0x100000)

using namespace std;

int main() {
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint num_devices, num_platforms;
    cl_int err;

    // get platform and device
    err = clGetPlatformIDs(1, &platform_id, &num_platforms);
    err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices);

    // create context
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &err);

    // create command queue
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &err);

    // create program from kernel source
    const char *kernel_source = 
    "__kernel void collatz_sequence(__global int *output, int start, int length) {\n"
    "    int idx = get_global_id(0);\n"
    "    int n = start + idx;\n"
    "    int count = 1;\n"
    "    while (n != 1) {\n"
    "        if (n % 2 == 0) {\n"
    "            n = n / 2;\n"
    "        } else {\n"
    "            n = 3 * n + 1;\n"
    "        }\n"
    "        count++;\n"
    "    }\n"
    "    output[idx] = count;\n"
    "}";

    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&kernel_source, NULL, &err);

    // build program
    err = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    // create kernel
    cl_kernel kernel = clCreateKernel(program, "collatz_sequence", &err);

    // set kernel arguments
    int start = 1;
    int length = 10;
    int *output = new int[length];
    cl_mem output_buffer = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * length, NULL, &err);
    err = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&output_buffer);
    err = clSetKernelArg(kernel, 1, sizeof(int), (void *)&start);
    err = clSetKernelArg(kernel, 2, sizeof(int), (void *)&length);

    // execute kernel
    size_t global_size = length;
    size_t local_size = 1;
    err = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_size, &local_size, 0, NULL, NULL);

    // read output buffer
    err = clEnqueueReadBuffer(command_queue, output_buffer, CL_TRUE, 0, sizeof(int) * length, output, 0, NULL, NULL);

    // print result
    for (int i = 0; i < length; i++) {
        cout << "Sequence starting from " << start + i << ": " << output[i] <<

EnvironmentControllerKata
=========================

What is the best way to design a test that needs to check several things about the state of the system? This example is a part of an environmental control system. One test should check that when the temperature is very cold, the alarm, header, and blower are all turned on. There are other tests which check the state of the system in other conditions.

Look at the example test cases and decide which design you find easiest to understand and work with.

I have a feeling the DSL that Bob chose for his example isn't as readable as he thinks it is. I think you could do better. Re-write the test using Approvals and design a better Printer.

Re-evaluate which test cases you find easiest to understand and work with.


## Acknowledgements

This exercise is based on an example in the book "Clean Code" by Robert C. Martin, pages 128-129.

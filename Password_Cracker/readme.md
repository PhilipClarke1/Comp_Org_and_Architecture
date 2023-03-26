#  Dictionary-based password cracker using the C crypt utility

Program takes a shadow password file consisting of usernames and password hashes and a dictionary of candidate passwords as input. Determines the true password for each user through the calculation of the hash of the entries in the candidate file compared the the hashes in the shadow password file. 
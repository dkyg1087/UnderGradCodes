# -*- coding: utf-8 -*-
import random
import os
def check_random_number_generator():
    random.seed(9898,version=2)
    standard_data = [357, 804, 993, 878, 862, 877, 183, 239, 707, 848, 96, 
                     119, 182, 427, 931, 761, 902, 71, 715, 299, 622, 917, 
                     290, 882, 709, 745, 66, 258, 136, 227, 209, 886, 928, 
                     608, 968, 220, 570, 862, 499, 657, 755, 805, 771, 170, 
                     842, 817, 275, 629, 456, 297, 238, 846, 214, 449, 780, 
                     962, 76, 869, 981, 616, 520, 177, 751, 668, 651, 606, 
                     251, 634, 505, 246, 466, 222, 495, 671, 365, 684, 719, 
                     769, 767, 398, 681, 628, 226, 103, 185, 686, 230, 623, 
                     210, 142, 882, 397, 168, 367, 553, 517, 492, 413, 928, 463]
    data = [random.randrange(1000) for _ in range(100)]
    if data != standard_data:
        raise ImportError 
    else:
        try:
            os.environ['TMP']
            print('Your Python environment can be used for the midterm examination.')
        except:
            print('no environment variable TMP')


check_random_number_generator()
        
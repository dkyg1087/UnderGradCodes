"""
1.site-packages

2.30個

3.fftpack.py

4.因為  在my_package/__init__.py裡,__name____name__ 為my_package

        但在my_package/utilities/__init__.py裡,__name____name__ 為my_package.utilities

        在lopen.py模組裡, __name____name__ 為my_package.utilities.lopen

今天要使用my_package.utilities.lopen.my_open就要從my_package.utilities中拿取__init__.py,

只寫my_package系統會不知道要拿my_package中的__init__.py還是my_package/utilities/__init__.py

import numpy as np,透過將numpy從新命名為np躲掉名稱衝突,所以系統並不會因為不知道要拿哪個檔案而發生衝突
"""
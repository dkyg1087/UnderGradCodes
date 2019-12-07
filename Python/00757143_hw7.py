import webbrowser
import argparse
parser = argparse.ArgumentParser(description="開啟網頁")
parser.add_argument("-u","--string",type=str,help="開啟的網頁")
args = parser.parse_args()
if args.string:
    webbrowser.open(args.string)
else:
    webbrowser.open("http://www.ntou.edu.tw")
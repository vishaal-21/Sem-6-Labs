from django.shortcuts import render

def home(request):
    return render(request,'home.html')

def meta(request):
    return render(request,'metadata.html')

def review(request):
    return render(request,'review.html')

def info(request):
    return render(request,'info.html')

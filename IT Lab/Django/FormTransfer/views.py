from django.shortcuts import render, redirect
from .forms import Transfer 

def index(request):
    if request.method=='POST':
        form=Transfer(request.POST)

        if form.is_valid():
            request.session['car']=form.cleaned_data['car']
            request.session['model']=form.cleaned_data['model']
            return redirect('new_page')
    else: 
        form=Transfer()

    return render(request,'form.html',{'form':form})

def new_page(request):
    car=request.session.get('car','')
    model=request.session.get('model','')

    return render(request,'second.html',{'car':car,'model':model})


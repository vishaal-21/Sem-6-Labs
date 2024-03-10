from django.shortcuts import render
from .forms import FormTransfer 

def index(request):
    context={}
    form=FormTransfer(request.POST or None)
    context['form']=form
    return render(request,'form.html')
